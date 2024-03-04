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

int classifier;
int distance_to_target;
bool alert;
bool pause;
bool slowdown;
int state;
bool turnoffUVC;

class CopilotRV : public rclcpp::Node {
  public:
    CopilotRV() : Node("copilotrv") {
      classifier_subscription_ = this->create_subscription<int>(
        "/sRobotClassifier", 10,
        std::bind(&CopilotRV::classifier_callback, this, _1));

      distance_to_target_subscription_ = this->create_subscription<int>(
        "/scan", 10,
        std::bind(&CopilotRV::distance_to_target_callback, this, _1));

      alert_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
        "/sRobotAlert", 10,
        std::bind(&CopilotRV::alert_callback, this, _1));

      pause_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
        "/sRobotPause", 10,
        std::bind(&CopilotRV::pause_callback, this, _1));

      slowdown_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
        "/sRobotSlowdown", 10,
        std::bind(&CopilotRV::slowdown_callback, this, _1));

      state_subscription_ = this->create_subscription<int>(
        "/sRobotState", 10,
        std::bind(&CopilotRV::state_callback, this, _1));

      turnoffUVC_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
        "/sRobotTurnoffUVC", 10,
        std::bind(&CopilotRV::turnoffUVC_callback, this, _1));

      handlerpropWorker_state_req_001_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_001", 10);

      handlerpropDtt_assumption_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropDtt_assumption", 10);

      handlerpropAdult_state_req001_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req001", 10);

      handlerpropAdult_state_req002_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req002", 10);

      handlerpropAdult_state_req003_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req003", 10);

      handlerpropWorker_state_req_002_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_002", 10);

      handlerpropWorker_state_req_003_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_003", 10);

      handlerpropClassifier_empty_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropClassifier_empty", 10);

      handlerpropOperationalstate_req004_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req004", 10);

      handlerpropOperationalstate_req001_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req001", 10);

      handlerpropOperationalstate_req002_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req002", 10);

      handlerpropClassifier_assumption_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropClassifier_assumption", 10);

      handlerpropWorker_state_req004_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req004", 10);

      handlerpropOperationalstate_req003_publisher_ = this->create_publisher<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req003", 10);

    }

    // Report (publish) monitor violations.
    void handlerpropWorker_state_req_001() {
      auto output = std_msgs::msg::Empty();
      handlerpropWorker_state_req_001_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropDtt_assumption() {
      auto output = std_msgs::msg::Empty();
      handlerpropDtt_assumption_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropAdult_state_req001() {
      auto output = std_msgs::msg::Empty();
      handlerpropAdult_state_req001_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropAdult_state_req002() {
      auto output = std_msgs::msg::Empty();
      handlerpropAdult_state_req002_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropAdult_state_req003() {
      auto output = std_msgs::msg::Empty();
      handlerpropAdult_state_req003_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropWorker_state_req_002() {
      auto output = std_msgs::msg::Empty();
      handlerpropWorker_state_req_002_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropWorker_state_req_003() {
      auto output = std_msgs::msg::Empty();
      handlerpropWorker_state_req_003_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropClassifier_empty() {
      auto output = std_msgs::msg::Empty();
      handlerpropClassifier_empty_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropOperationalstate_req004() {
      auto output = std_msgs::msg::Empty();
      handlerpropOperationalstate_req004_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropOperationalstate_req001() {
      auto output = std_msgs::msg::Empty();
      handlerpropOperationalstate_req001_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropOperationalstate_req002() {
      auto output = std_msgs::msg::Empty();
      handlerpropOperationalstate_req002_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropClassifier_assumption() {
      auto output = std_msgs::msg::Empty();
      handlerpropClassifier_assumption_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropWorker_state_req004() {
      auto output = std_msgs::msg::Empty();
      handlerpropWorker_state_req004_publisher_->publish(output);
    }

    // Report (publish) monitor violations.
    void handlerpropOperationalstate_req003() {
      auto output = std_msgs::msg::Empty();
      handlerpropOperationalstate_req003_publisher_->publish(output);
    }

    // Needed so we can report messages to the log.
    static CopilotRV& getInstance() {
      static CopilotRV instance;
      return instance;
    }

  private:
    void classifier_callback(const int::SharedPtr msg) const {
      classifier = msg->data;
      step();
    }

    void distance_to_target_callback(const int::SharedPtr msg) const {
      distance_to_target = msg->data;
      step();
    }

    void alert_callback(const std_msgs::msg::Bool::SharedPtr msg) const {
      alert = msg->data;
      step();
    }

    void pause_callback(const std_msgs::msg::Bool::SharedPtr msg) const {
      pause = msg->data;
      step();
    }

    void slowdown_callback(const std_msgs::msg::Bool::SharedPtr msg) const {
      slowdown = msg->data;
      step();
    }

    void state_callback(const int::SharedPtr msg) const {
      state = msg->data;
      step();
    }

    void turnoffUVC_callback(const std_msgs::msg::Bool::SharedPtr msg) const {
      turnoffUVC = msg->data;
      step();
    }

    rclcpp::Subscription<int>::SharedPtr classifier_subscription_;

    rclcpp::Subscription<int>::SharedPtr distance_to_target_subscription_;

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr alert_subscription_;

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr pause_subscription_;

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr slowdown_subscription_;

    rclcpp::Subscription<int>::SharedPtr state_subscription_;

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr turnoffUVC_subscription_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_001_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropDtt_assumption_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req001_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req002_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req003_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_002_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_003_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropClassifier_empty_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req004_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req001_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req002_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropClassifier_assumption_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req004_publisher_;

    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req003_publisher_;

};

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropWorker_state_req_001() {
  CopilotRV::getInstance().handlerpropWorker_state_req_001();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropDtt_assumption() {
  CopilotRV::getInstance().handlerpropDtt_assumption();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropAdult_state_req001() {
  CopilotRV::getInstance().handlerpropAdult_state_req001();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropAdult_state_req002() {
  CopilotRV::getInstance().handlerpropAdult_state_req002();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropAdult_state_req003() {
  CopilotRV::getInstance().handlerpropAdult_state_req003();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropWorker_state_req_002() {
  CopilotRV::getInstance().handlerpropWorker_state_req_002();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropWorker_state_req_003() {
  CopilotRV::getInstance().handlerpropWorker_state_req_003();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropClassifier_empty() {
  CopilotRV::getInstance().handlerpropClassifier_empty();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropOperationalstate_req004() {
  CopilotRV::getInstance().handlerpropOperationalstate_req004();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropOperationalstate_req001() {
  CopilotRV::getInstance().handlerpropOperationalstate_req001();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropOperationalstate_req002() {
  CopilotRV::getInstance().handlerpropOperationalstate_req002();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropClassifier_assumption() {
  CopilotRV::getInstance().handlerpropClassifier_assumption();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropWorker_state_req004() {
  CopilotRV::getInstance().handlerpropWorker_state_req004();
}

// Pass monitor violations to the actual class, which has ways to
// communicate with other applications.
void handlerpropOperationalstate_req003() {
  CopilotRV::getInstance().handlerpropOperationalstate_req003();
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CopilotRV>());
  rclcpp::shutdown();
  return 0;
}
