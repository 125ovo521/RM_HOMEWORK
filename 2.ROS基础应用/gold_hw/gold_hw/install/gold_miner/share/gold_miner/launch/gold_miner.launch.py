import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import yaml
# from launch.actions import DeclareLaunchArgument, LogInfo
# from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    params_file = os.path.join(
        get_package_share_directory('gold_miner'), 'config', 'param.yaml'
    )

    mining_industry = Node(
        package='gold_miner',
        executable='mining_industry',
        parameters=[params_file],
        output="screen",
    )

    miner = Node(
        package='gold_miner',
        executable='miner',
        # parameters=[params_file],
        output="screen",
    )

    ld = LaunchDescription([
    #    DeclareLaunchArgument('params_file', default_value='params.yaml'),
        mining_industry,
        miner,
    ])

    return ld