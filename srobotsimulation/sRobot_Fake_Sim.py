import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Bool

class sRobotSimulator(Node):
    def __init__(self):
        super().__init__('srobot_simulator') # Create a node with the name 'srobot_simulator'
        # Create publishers for the different topics
        self.classifier_publisher = self.create_publisher(Int32, '/sRobotClassifier', 10)
        self.alert_publisher = self.create_publisher(Bool, '/sRobotAlert', 10)
        self.pause_publisher = self.create_publisher(Bool, '/sRobotPause', 10)
        self.slowdown_publisher = self.create_publisher(Bool, '/sRobotSlowdown', 10)
        self.state_publisher = self.create_publisher(Int32, '/sRobotState', 10)
        self.turnoff_uvc_publisher = self.create_publisher(Bool, '/sRobotTurnoffUVC', 10)

        self.interval_counter = 0 # Counter to keep track of the interval

        self.timer = self.create_timer(0.5, self.publish_messages) # Create a timer that calls the publish_messages method every two seconds

    def publish_messages(self):
        # Increment the interval counter
        self.interval_counter += 1

        # Interval 1: Publish specific values when the counter is odd
        if self.interval_counter % 2 != 0: 
            self.publish_interval_1_values()
        # Interval 2: Publish a different set of specific values when the counter is even
        elif self.interval_counter % 2 == 0:
            self.publish_interval_2_values()

    def publish_interval_1_values(self):
        self.classifier_publisher.publish(Int32(data=1))
        self.alert_publisher.publish(Bool(data=True))
        self.pause_publisher.publish(Bool(data=False))
        self.slowdown_publisher.publish(Bool(data=True))
        self.state_publisher.publish(Int32(data=2))
        self.turnoff_uvc_publisher.publish(Bool(data=False))
        self.get_logger().info('Published interval 1 values.')

    def publish_interval_2_values(self):
        self.classifier_publisher.publish(Int32(data=3))
        self.alert_publisher.publish(Bool(data=False))
        self.pause_publisher.publish(Bool(data=True))
        self.slowdown_publisher.publish(Bool(data=False))
        self.state_publisher.publish(Int32(data=4))
        self.turnoff_uvc_publisher.publish(Bool(data=True))
        self.get_logger().info('Published interval 2 values.')

def main(args=None):
    rclpy.init(args=args)
    srobot_simulator = sRobotSimulator()

    rclpy.spin(srobot_simulator)

    srobot_simulator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()