#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/empty.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "std_msgs/msg/u_int16.hpp"
#include "std_msgs/msg/u_int32.hpp"
#include "std_msgs/msg/u_int64.hpp"
#include "std_msgs/msg/int8.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/float64.hpp"
#include <cstdint>

#include "monitor.h"
#include "monitor.c"

using std::placeholders::_1;


class CopilotRV : public rclcpp::Node {
  public:
    CopilotRV() : Node("copilotrv") {

      handlerpropClass_assumption_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropClass_assumption", 10);

      handlerpropWorker_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker", 10);

      handlerpropGreen_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropGreen", 10);

      handlerpropYellow_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropYellow", 10);

      handlerpropRed_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropRed", 10);

      handlerpropDtt_assumption_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropDtt_assumption", 10);

    }

    // Report (publish) monitor violations.
    void handlerpropClass_assumption() {
      auto output = std_msgs::msg::Empty();
      handlerpropClass_assumption_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropWorker() {
      auto output = std_msgs::msg::Empty();
      handlerpropWorker_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropGreen() {
      auto output = std_msgs::msg::Empty();
      handlerpropGreen_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropYellow() {
      auto output = std_msgs::msg::Empty();
      handlerpropYellow_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropRed() {
      auto output = std_msgs::msg::Empty();
      handlerpropRed_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropDtt_assumption() {
      auto output = std_msgs::msg::Empty();
      handlerpropDtt_assumption_publisher_->publish(output);
    }

    // Needed so we can report messages to the log.
    static CopilotRV& getInstance() {
      static CopilotRV instance;
      return instance;
    }

  private:


    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropClass_assumption_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropGreen_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropYellow_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropRed_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropDtt_assumption_publisher_;

};

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropClass_assumption() {
  CopilotRV::getInstance().handlerpropClass_assumption();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropWorker() {
  CopilotRV::getInstance().handlerpropWorker();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropGreen() {
  CopilotRV::getInstance().handlerpropGreen();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropYellow() {
  CopilotRV::getInstance().handlerpropYellow();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropRed() {
  CopilotRV::getInstance().handlerpropRed();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropDtt_assumption() {
  CopilotRV::getInstance().handlerpropDtt_assumption();
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CopilotRV>());
  rclcpp::shutdown();
  return 0;
}
