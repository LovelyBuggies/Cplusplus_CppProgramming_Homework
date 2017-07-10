
#include "Namespace.hpp"

using namespace mfc;
using namespace owl;

void Handle()
{
  mfc::inflag++;
  owl::inflag--;
  ::inflag %= 100;
}