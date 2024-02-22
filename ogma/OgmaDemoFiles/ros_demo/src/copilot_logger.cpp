#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/empty.hpp"

using std::placeholders::_1;

class CopilotLogger : public rclcpp::Node {
  public:
    CopilotLogger() : Node("copilotlogger") {
      handlerpropClass_assumption_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropClass_assumption", 10,
        std::bind(&CopilotLogger::handlerpropClass_assumption_callback, this, _1));

      handlerpropWorker_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropWorker", 10,
        std::bind(&CopilotLogger::handlerpropWorker_callback, this, _1));

      handlerpropGreen_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropGreen", 10,
        std::bind(&CopilotLogger::handlerpropGreen_callback, this, _1));

      handlerpropYellow_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropYellow", 10,
        std::bind(&CopilotLogger::handlerpropYellow_callback, this, _1));

      handlerpropRed_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropRed", 10,
        std::bind(&CopilotLogger::handlerpropRed_callback, this, _1));

      handlerpropDtt_assumption_subscription_ = this->create_subscription<std_msgs::msg::Empty>(
        "copilot/handlerpropDtt_assumption", 10,
        std::bind(&CopilotLogger::handlerpropDtt_assumption_callback, this, _1));

    }

  private:
    void handlerpropClass_assumption_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropClass_assumption");
    }

    void handlerpropWorker_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropWorker");
    }

    void handlerpropGreen_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropGreen");
    }

    void handlerpropYellow_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropYellow");
    }

    void handlerpropRed_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropRed");
    }

    void handlerpropDtt_assumption_callback(const std_msgs::msg::Empty::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "Copilot monitor violation: handlerpropDtt_assumption");
    }

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropClass_assumption_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropWorker_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropGreen_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropYellow_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropRed_subscription_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr handlerpropDtt_assumption_subscription_;

};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CopilotLogger>());
  rclcpp::shutdown();
  return 0;
}
