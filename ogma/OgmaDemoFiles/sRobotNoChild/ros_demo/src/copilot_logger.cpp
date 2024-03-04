#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/empty.hpp"

using std::placeholders::_1;

class CopilotLogger : public rclcpp::Node {
  public:
    CopilotLogger() : Node("copilotlogger") {
      handlerpropWorker_state_req_001_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_001", 10,
        std::bind(&CopilotLogger::handlerpropWorker_state_req_001_callback, this, _1));

      handlerpropDtt_assumption_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropDtt_assumption", 10,
        std::bind(&CopilotLogger::handlerpropDtt_assumption_callback, this, _1));

      handlerpropAdult_state_req001_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req001", 10,
        std::bind(&CopilotLogger::handlerpropAdult_state_req001_callback, this, _1));

      handlerpropAdult_state_req002_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req002", 10,
        std::bind(&CopilotLogger::handlerpropAdult_state_req002_callback, this, _1));

      handlerpropAdult_state_req003_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropAdult_state_req003", 10,
        std::bind(&CopilotLogger::handlerpropAdult_state_req003_callback, this, _1));

      handlerpropWorker_state_req_002_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_002", 10,
        std::bind(&CopilotLogger::handlerpropWorker_state_req_002_callback, this, _1));

      handlerpropWorker_state_req_003_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req_003", 10,
        std::bind(&CopilotLogger::handlerpropWorker_state_req_003_callback, this, _1));

      handlerpropClassifier_empty_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropClassifier_empty", 10,
        std::bind(&CopilotLogger::handlerpropClassifier_empty_callback, this, _1));

      handlerpropOperationalstate_req004_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req004", 10,
        std::bind(&CopilotLogger::handlerpropOperationalstate_req004_callback, this, _1));

      handlerpropOperationalstate_req001_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req001", 10,
        std::bind(&CopilotLogger::handlerpropOperationalstate_req001_callback, this, _1));

      handlerpropOperationalstate_req002_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req002", 10,
        std::bind(&CopilotLogger::handlerpropOperationalstate_req002_callback, this, _1));

      handlerpropClassifier_assumption_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropClassifier_assumption", 10,
        std::bind(&CopilotLogger::handlerpropClassifier_assumption_callback, this, _1));

      handlerpropWorker_state_req004_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker_state_req004", 10,
        std::bind(&CopilotLogger::handlerpropWorker_state_req004_callback, this, _1));

      handlerpropOperationalstate_req003_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropOperationalstate_req003", 10,
        std::bind(&CopilotLogger::handlerpropOperationalstate_req003_callback, this, _1));

    }

  private:
    void handlerpropWorker_state_req_001_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropWorker_state_req_001");
    }

    void handlerpropDtt_assumption_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropDtt_assumption");
    }

    void handlerpropAdult_state_req001_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropAdult_state_req001");
    }

    void handlerpropAdult_state_req002_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropAdult_state_req002");
    }

    void handlerpropAdult_state_req003_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropAdult_state_req003");
    }

    void handlerpropWorker_state_req_002_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropWorker_state_req_002");
    }

    void handlerpropWorker_state_req_003_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropWorker_state_req_003");
    }

    void handlerpropClassifier_empty_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropClassifier_empty");
    }

    void handlerpropOperationalstate_req004_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropOperationalstate_req004");
    }

    void handlerpropOperationalstate_req001_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropOperationalstate_req001");
    }

    void handlerpropOperationalstate_req002_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropOperationalstate_req002");
    }

    void handlerpropClassifier_assumption_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropClassifier_assumption");
    }

    void handlerpropWorker_state_req004_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropWorker_state_req004");
    }

    void handlerpropOperationalstate_req003_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropOperationalstate_req003");
    }

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_001_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropDtt_assumption_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req001_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req002_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropAdult_state_req003_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_002_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req_003_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropClassifier_empty_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req004_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req001_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req002_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropClassifier_assumption_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_state_req004_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropOperationalstate_req003_subscription_;

};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CopilotLogger>());
  rclcpp::shutdown();
  return 0;
}
