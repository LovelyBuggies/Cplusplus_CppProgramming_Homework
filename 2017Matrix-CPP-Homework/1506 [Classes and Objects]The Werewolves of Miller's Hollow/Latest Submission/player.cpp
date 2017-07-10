#include "player.hpp"
#include "judge.hpp"
#include <iostream>

using namespace std;

Player::Player()
{}

Player::~Player()
{}

void Player::init(std::string name, Role role)
{
  m_role=role;
  m_name=name;
  return ;
}

Player::Role Player::role() const
{
  return (m_role);
}

void Player::answer() const
{
  if (m_role==2) cout << m_name << ": Shh... I am a Werewolf." << endl;
  else if (m_role==3) cout << m_name << ": Shh... I am a Seer." << endl;
  else if (m_role==4) cout << m_name << ": Shh... I am a Witch." << endl;
  else if (m_role==5) cout << m_name << ": Shh... I am a Hunter." << endl;
}

void Player::pretend() const
{
  std::cout << m_name << ": I am the villager!!" << std::endl;
}