#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<time.h>
#include<thread>
#include<stack>

using namespace std;


class Card {
private:
    int _value;
    int _suit;
public:
    Card(const int value, const int suit) {
        _value = value;
        _suit = suit;
    }
    int getSuit() {
        return(_suit);
    }
    int getValue() {
        return(_value);
    }

    //Card::Card(const int value, const int suit);
};

template <typename A>

//A& a -> passing a reference of type A to the function -> template <typename A>
void shuffle(A& a, int i = 0, const int j = 52) {
    const int _j = j - 1;
    for (; i < j; i++) {
        srand(time(NULL));
        const int k = i + rand() % (j - i);
        auto tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}

void load(vector<Card> orignalArr, stack<Card>& stack) {
    int n = orignalArr.size();
    for (int i = 0; i < n; i++) {
        stack.push(orignalArr[i]);
    }
}

void deal(vector<Card>& playerCards, int numCards, stack<Card> deck) {
    for (int i = 0; i < numCards; i++) {
        playerCards.insert(playerCards.begin(), deck.top());
        deck.pop();
    }
}

int main() {
    static const char* suit[5] = { "","Hearts", "Diamonds", "Clubs", "Spades" };  //suit array
    static const char* face[14] =
    { "","Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    int numPlayers = 4;
    Card CardC(0, 0);
    vector<Card> cards(52, CardC);
    int c = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            cards[c] = Card(i, j);
            ++c;
        }
    }
    shuffle(cards);
    stack<Card> deck;
    load(cards, deck);

    //cout << ceil(52/4);

    vector<vector<Card>> playerCards(numPlayers, vector<Card>(1, Card(0, 0)));
    deal(playerCards[0], 10, deck);



    for (auto& o : playerCards[0]) {
        cout << face[o.getValue()] << suit[o.getSuit()] << endl;
        cout << o.getSuit() << o.getValue() << endl;
    }
    //while(!deck.empty()){
    //    cout << deck.top().getValue() << deck.top().getSuit() << endl;
    //    deck.pop();
    //}
}