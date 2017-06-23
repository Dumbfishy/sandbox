
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

enum CardRANK {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    RANK_MAX
};

enum CardSUIT {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    SUIT_MAX
};

struct Card {
    CardRANK rank;
    CardSUIT suit;
};

void printCard(const Card &card);
void printDeck(const std::array<Card,52> &deck);
void swapCard(Card &card1, Card &card2);
void shuffleDeck(std::array<Card,52> &deck);
int getCardValue(Card &card);
int playBlackjack(std::array<Card,52> &deck);

int main (void) 
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card,52> deck;

    for (int i = 0; i < SUIT_MAX; i++) {
        for (int j = 0; j < RANK_MAX; j++) {
            deck[i*13 + j].suit = static_cast<CardSUIT>(i);
            deck[i*13 + j].rank = static_cast<CardRANK>(j);
        }
    }

    bool playGame = true;
    int result = 0;
    bool playAgain = true;
    char playerAction;

    while (playGame == true) {

        cout << "Lets Play BlackJack!" << endl;
    
        result = playBlackjack(deck);
        //outcome
        if (result == 1) {
            cout << "Player Wins!" << endl;
        } else if (result == 2) {
            cout << "Player Loses :(" << endl;
        } else if (result == 0) {
            cout << "PUSH!" << endl;
        }
        cout << "Game Over" << endl;


        cout << "Play Again? (Y)es/(N)o: ";
        cin >> playerAction;

        if (playerAction == 'N' || playerAction == 'n') {
            cout << "Goodbye" << endl;
            playGame = false;
        } else if (playerAction == 'Y' || playerAction == 'y') {
            cout << "Shuffling the Deck..." << endl;
            shuffleDeck(deck);
        } else {
            cout << "sorry, invalid chose rx'ed" << endl;
        }
    }

    printDeck(deck);
    cout << endl;
  
    return 0;
}

int playBlackjack(std::array<Card,52> &deck)
{
    bool playerHand = true;
    bool dealerHand = true;
    int playerScore = 0;
    int dealerScore = 0;
    Card *cardPtr = &deck[0];
    char playerAction;
    
    shuffleDeck(deck);
    // Get Players Hand
    playerScore += getCardValue(*cardPtr++);
    dealerScore += getCardValue(*cardPtr++);

    cout << "Dealer Shows: " << dealerScore << endl;

    playerScore += getCardValue(*cardPtr++);
    dealerScore += getCardValue(*cardPtr++);
    
    cout << "Player Shows : " << playerScore << endl;

    //playing the game
    while (playerHand == true) {
        cout << "Select action: (H)it, (S)tand ";
        cin >> playerAction;

        if (playerAction == 'H' || playerAction == 'h') {
            cout << "Hit!" << endl;
            playerScore += getCardValue(*cardPtr++);
        } else if (playerAction == 'S' || playerAction == 's') {
            cout << "Stand!" << endl;
            playerHand = false;
        } else {
            cout << "sorry, invalid chose rx'ed" << endl;
        }

        cout << "Player Shows : " << playerScore << endl;
        if (playerScore > 21) {
            cout << "BUST!" << endl;
            playerHand = false;
            dealerHand = false;
            return 2;
        }
    }

    cout << "Dealer Shows : " << dealerScore << endl;
    //Get Dealer's score
    while (dealerScore < 17) {
        if (dealerScore < 17) {
            cout << "Dealer Hits!" << endl;
            dealerScore += getCardValue(*cardPtr++);
        } else if (dealerScore > 16 || dealerScore < 22) {
            cout << "Dealers Stands!" << endl;
        }

        cout << "Dealer Shows : " << dealerScore << endl;
        if (dealerScore > 21) {
            cout << "Dealer BUSTS!" << endl;
            return 1;
        }
    }

    if (dealerScore == playerScore) {
        return 0;
    } else if (dealerScore > playerScore) {
        return 2;
    } else if (dealerScore < playerScore) {
        return 1;
    }
}


int getCardValue(Card &card)
{
    if (card.rank <= RANK_10) {
        return (card.rank + 2);
    } else {
        switch (card.rank) {
            case RANK_JACK:
            case RANK_QUEEN:
            case RANK_KING:
                return 10;
            case RANK_ACE:
                return 11;
            default:
                break;
        }
    }

    return -1;
}

void shuffleDeck(std::array<Card,52> &deck)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    for (auto &card : deck) {
        swapCard(card,deck[static_cast<int>(rand() * fraction * (51))]);
    }

}


void swapCard(Card &card1, Card &card2)
{
    
    Card tmp = card1;
    card1 = card2;
    card2 = tmp;
}

void printDeck(const std::array<Card,52> &deck) {
    for (const auto &card : deck) {
        printCard(card);
        cout << ",";
    }
    cout << endl;
}

void printCard(const Card &card)
{
    if (card.rank <= RANK_10) {
        cout << (card.rank + 2);
    } else {
        switch (card.rank) {
            case RANK_JACK:
                cout << "J";
                break;
            case RANK_QUEEN:
                cout << "Q";
                break;
            case RANK_KING:
                cout << "K";
                break;
            case RANK_ACE:
                cout << "A";
                break;
            default:
                break;
        }
    }

    switch (card.suit) {
        case SUIT_HEART:
            cout << "h";
            break;
        case SUIT_SPADE:
            cout << "s";
            break;
        case SUIT_CLUB:
            cout << "c";
            break;
        case SUIT_DIAMOND:
            cout << "d";
            break;
        default:
            break;
    }

}

