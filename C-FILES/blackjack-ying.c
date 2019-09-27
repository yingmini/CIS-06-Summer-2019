#include <cairo.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * Ying Lin
 * yinghsuen@gmail.com
 * 11005909
 * BLACKJACK TYPE DEFINITIONS
 *
 * These are custom data types defined for blackjack.
 * Do not modify or move these definitions.
 */

char *suit_labels[4] = {
  "Clubs",
  "Diamonds",
  "Hearts",
  "Spades"
};

char *rank_labels[13] = {
  "2",  
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "Jack",
  "King",
  "Queen",
  "Ace"
};

typedef enum {
  CLUBS,
  DIAMONDS,
  HEARTS,
  SPADES
} suit_t;

typedef enum {
  TWO, 
  THREE, 
  FOUR, 
  FIVE, 
  SIX, 
  SEVEN, 
  EIGHT, 
  NINE,
  TEN,
  JACK, 
  KING, 
  QUEEN, 
  ACE
} rank_t;

typedef struct {
  rank_t rank;
  suit_t suit;
  char *suit_label;
  char *rank_label;
  char file_path[256];
  cairo_surface_t *img;
  int x;
  int y;
  int is_visible;
} card_t;

/**
 * BLACKJACK STATE VARIABLES
 *
 * These global variables hold the state for the application.
 * Do not move these variable definitions.
 * Changing these variables will change the state of the game.
 */

card_t deck[52];
card_t dealer_hand[12];
card_t player_hand[12];
unsigned int dealer_card_count = 0;
unsigned int dealer_hand_value = 0;
unsigned int player_card_count = 0;
unsigned int player_hand_value = 0;
int DEALER_X;
int DEALER_Y;
int PLAYER_X;
int PLAYER_Y;
int hand_winner = -1; // -1 = in progress, 0 = draw, 1 = dealer, 2 = player
int player_money = 1000;
int player_bet = 0;

void init_deck()
{
  srand(time(NULL));

  // TODO: fill the deck array with card structs.
  // You should have 52 cards (one of each rank for each suit).
  // You can use this for loop to help you:
  //
  // for (int i = CLUBS; i <= SPADES; i++)
  // {
  //   for (int j = TWO; j <= ACE; j++)
  //   {
  //      modify each struct in the array to have the correct data
  //      to reflect a deck of cards. 
  //   }
  // }
  //
  int n=0;
  for (int i = CLUBS; i <= SPADES; i++)
  {
    //Inner: rank
    
    for (int j =TWO; j <= ACE; j++)
    {
      deck[n].rank = j;
      deck[n].suit = i;
      
      deck[n].rank_label = rank_labels[j];
      deck[n].suit_label = suit_labels[i];
      
      sprintf(
        deck[n].file_path, 
        "data/card%s%s.png", 
        suit_labels[i], 
        rank_labels[j]);
  
      deck[n].img = cairo_image_surface_create_from_png(deck[n].file_path);
      n++;
    }
        
  }
}
  
  // Here is an example of initializing a single card that you may use:
  

void clear_hand()
{ 
  // TODO: Loop through dealer_hand and player_hand,
  // Reset the value of every struct to be empty.
  card_t empty;
  for (int i = 0; i < 12; i++)
  {
    player_hand[i] = empty;
    dealer_hand[i] = empty;
  }
  dealer_card_count = 0;
  dealer_hand_value = 0;

  player_card_count = 0;
  player_hand_value = 0;

  hand_winner = -1;
}

int get_card_value(rank_t rank, int current_hand_value)
{
  // TODO: return the point value of the card based on the value of the hand.
  
  // Ranks TWO - TEN are worth their enum value + 2
  // For example, rank + 2 would work.
  
  // Ranks JACK - KING are worth 10
  
  // ACE is worth either 11 or 1. 
  // If adding 11 to the current hand makes the hand greater than 21, the value is only 1.
  
  // Remove this return after you've implemented the logic above.
  int val;
  
  if(rank > TEN)
  {
    if(rank != ACE)
    {val = 10;}
    else
    {
      val =11;
      if(current_hand_value + val > 21)
      {val = 1;}
    }
  }
  else
  {
    val = rank+2;
  }
  
  return val;
}

void deal_to_dealer(unsigned int num)
{
  // TODO: deal the number of cards requested to the dealer.
  // All dealt cards 
  for (int i = 0; i < num; i++)
  {
  // Pick one random card from the deck.
  card_t dealt = deck[rand() % 52];
  dealer_hand[dealer_card_count] = dealt;
  dealer_card_count += 1;
  dealer_hand_value = dealer_hand_value + get_card_value(dealt.rank, player_hand_value);
  printf("dealt to dealer: %s\n", dealt.rank_label);
  }
}

void deal_to_player(unsigned int num)
{
  // TODO: implement the same algorithm.
  for (int i=0; i < num; i++)
  {
  // Pick one random card from the deck.
    card_t dealt = deck[rand() % 52];
    player_hand[player_card_count] = dealt;
    player_card_count += 1;
    player_hand_value = player_hand_value + get_card_value(dealt.rank, dealer_hand_value);
    printf("dealt to player: %s\n", dealt.rank_label);
    if(player_hand_value > 21){
      void set_winner();
    }  
  }
}

void set_winner()
{
  // TODO: compare player_hand_value and dealer_hand_value to determine the winner
  // Set the hand_winner variable with the appropriate value.
  if(dealer_hand_value > 21)
  {
    hand_winner = 2;
    player_money += player_bet;
  }
  else if(player_hand_value > 21)
  {
    hand_winner = 1;
    player_money -= player_bet;
  }
  else if(player_hand_value > dealer_hand_value)
  {
    hand_winner = 2;
    player_money += player_bet;
  }
  else if(dealer_hand_value > player_hand_value)
  {
    hand_winner = 1;
    player_money -= player_bet;
  }
  else
  {
    hand_winner = 0;
  }
}

void student_setup(cairo_t *cr, int width, int height)
{
  DEALER_X = width / 2 - 50;
  DEALER_Y = 25;
  PLAYER_X = width / 2 - 50;
  PLAYER_Y = height - 200; 

  // Initializes the deck.
  init_deck();

  // Deals 2 cards to the dealer and the player.
  deal_to_dealer(2);
  deal_to_player(2);
}

/**
 * Handles clicking the "Hit" button.
 */
void student_handle_hit()
{
  deal_to_player(1);
}

/**
 * Handles clicking the "Stay" button.
 * This ends the users turn and continue to deals cards to the dealer until
 * either the dealer busts or their hand reaches at least 16. 
 */
void student_handle_stay()
{
  // TODO: implement 
  // While the value of the dealer_hand is less than 16 
  //   deal one card to the dealer
  // After, call set_winner()
  while(dealer_hand_value < 16)
  {
    deal_to_dealer;
  }
  if(hand_winner == -1)
  {
    void set_winner();
  }
}

void student_handle_plus()
{
  // TODO: increase player_bet by some amount
  player_bet += 10;
}

void student_handle_minus()
{
  // TODO: decrease player_bet by some amount
  player_bet -= 10;
}

void student_handle_deal()
{
  clear_hand();
  deal_to_dealer(2);
  deal_to_player(2);
}

void student_draw(cairo_t *cr, int width, int height)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_rectangle(cr, 0, 0, width, height); 
  cairo_fill(cr);

  // Display the dealer's hand
  for (int i = 0; i < dealer_card_count; i++)
  {
    if (dealer_hand[i].img != NULL)
    {
      cairo_set_source_surface(
        cr, 
        dealer_hand[i].img, 
        DEALER_X + i * 25, 
        DEALER_Y
      );
      cairo_paint(cr);
    }
  }
  
  // Display the player's hand
  for (int i = 0; i < player_card_count; i++)
  {
    if (player_hand[i].img != NULL)
    {
      cairo_set_source_surface(
        cr, 
        player_hand[i].img, 
        PLAYER_X + i * 25, 
        PLAYER_Y
      );
      cairo_paint(cr);
    }
  }

  cairo_set_source_rgb(cr, 255, 255, 255);
  cairo_set_font_size(cr, 13);
  cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  
  cairo_move_to(cr, 20, 20);
  cairo_show_text(cr, "Ying Lin");

  cairo_move_to(cr, 20, 40);
  char dealer_msg[256];
  sprintf(dealer_msg, "Dealer hand value: %d", dealer_hand_value);
  cairo_show_text(cr, dealer_msg);

  cairo_move_to(cr, 20, 60);
  char player_value_msg[256];
  sprintf(player_value_msg, "Player hand value: %d", player_hand_value);
  cairo_show_text(cr, player_value_msg);

  cairo_move_to(cr, 20, 80);
  char player_money_msg[256];
  sprintf(player_money_msg, "Player money: $%d", player_money);
  cairo_show_text(cr, player_money_msg);

  cairo_move_to(cr, 20, 100);
  char player_bet_msg[256];
  sprintf(player_bet_msg, "Player bet: $%d", player_bet);
  cairo_show_text(cr, player_bet_msg);

  if (hand_winner != -1)
  {
    cairo_set_source_rgb(cr, 255, 0, 0);
    cairo_set_font_size(cr, 20);
    cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    
    cairo_move_to(cr, 20, height / 2);

    if (hand_winner == 1)
    {
      cairo_show_text(cr, "Dealer won!"); 
    }
    else if (hand_winner == 2)
    {
      cairo_show_text(cr, "Player won!");
    }
    else if (hand_winner == 0)
    {
      cairo_show_text(cr, "Draw!");
    }
  }
}


