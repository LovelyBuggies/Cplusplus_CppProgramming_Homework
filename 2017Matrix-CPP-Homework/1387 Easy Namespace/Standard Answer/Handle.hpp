#include "Namespace.hpp"
void Handle() {
  owl::inflag--;
  mfc::inflag++;
  ::inflag %= 100;
}