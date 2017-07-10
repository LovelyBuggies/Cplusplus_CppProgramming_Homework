#include "judge.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

Judge::Judge()
{  
  m_players_count=0;
}

Judge::~Judge()
{  
}

void Judge::call(Player::Role role)
{
  std::cout << "Calling: ";
  switch(role){
    case 1: {
    cout<< "Villager" << std::endl;
    break;
  }
    case 2: {
     cout << "Werewolf" << endl;
    break;
  }
    case 3:{
     cout << "Seer" << endl;
    break;
  }
    case 4:{
    cout << "Witch" << endl;
    break;
  }
    case 5:{
    cout << "Hunter" << endl;
    break;
  }
    default:break;
  }
  if (role > 1)
   {
   for(m_players_count=0;m_players_count<kMaxCountOfPlayers;m_players_count++)
     if (  (*(m_players[m_players_count])).role()==role)
  (* (m_players[m_players_count]) ).answer();      
    }
  
  else 
   {
    for (m_players_count=0;m_players_count<kMaxCountOfPlayers;m_players_count++)
      (*  (m_players[m_players_count]) ).pretend();  
   }
   return ;   
}


void Judge::on(const Player* player)
{
  m_players[m_players_count]=player;
  m_players_count++;
}