#include "a.h"
#include "UBus.h"

NetworkManager::NetworkManager() {
  ubus = std::unique_ptr<UBus>(new UBus());
#ifdef __arm__
  ubus->Connect();
#endif  
}

NetworkManager::~NetworkManager() {
#ifdef __arm__  
  ubus->Disconnect();
#endif
}
