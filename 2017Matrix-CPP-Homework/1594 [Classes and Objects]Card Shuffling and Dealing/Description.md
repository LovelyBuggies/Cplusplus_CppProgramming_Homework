# [Classes and Objects]Card Shuffling and Dealing

*出题人： 劳思*     
## Description:  
In this exercise, you are required to implement two classes which consists of class Card, class DeckOfCards.

**The class Card should provide:**  

a)  Data members face and suit of type int.The range of face is [0,12],and the range of suit is [0,3].

b)  A constructor that receives two ints representing the face and suit and uses them to initialize the data members.

c)  Two static arrays of strings representing the faces and suits (which will be given below).

d)  A toString function that returns the Card as a string in the form "face of suit".

**The class DeckOfCards should contain:**  

a) A vector of Cards named deck to store the Cards.

b) An integer currentCard representing the next Card to deal.

c)  A default constructor that initialize the Cards in the deck.The constructor should use vector function push_back to add each Card to the end of the vector after the Card is created and initialized. This should be done for each of the 52 Cards in the deck.

d)  A dealCard function that returns the next Card object from the deck.

e)  A moreCards function that returns a bool value indicationg whether there are more Cards to deal. 

 

Example for form of Card:

If face is 0, suit is 0, then the form is "Ace of Hearts".

## Hints:  
- Face names (Ordered): "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
- Suit names (Ordered): "Hearts", "Diamonds", "Clubs", "Spades"
- **Order: Ace of Hearts, Deuce of Hearts...King of Hearts, Ace of Diamonds, Deuce of Diamonds...**    
-----
*出题人： 劳思*