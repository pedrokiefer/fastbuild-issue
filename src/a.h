#ifndef A_H_
#define A_H_

#include <memory>
class UBus;

class NetworkManager {
 private:
  std::unique_ptr<UBus> ubus;
 public:
  NetworkManager();
  virtual ~NetworkManager();
};

#endif // A_H_
