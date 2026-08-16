class Solution(object):
    def robotSim(self, commands, obstacles):
        directions = (0, 1, 0, -1, 0)
        obstacle_set = set((x, y) for x, y in obstacles)

        max_distance_squared = 0
        direction_index = 0

        current_x = 0
        current_y = 0

        for command in commands:
            if command == -2:
                direction_index = (direction_index + 3) % 4
            elif command == -1:
                direction_index = (direction_index + 1) % 4
            else:
                for _ in range(command):
                    next_x = current_x + directions[direction_index]
                    next_y = current_y + directions[direction_index + 1]

                    if (next_x, next_y) in obstacle_set:
                        break

                    current_x = next_x
                    current_y = next_y

                    max_distance_squared = max(
                        max_distance_squared,
                        current_x * current_x + current_y * current_y
                    )

        return max_distance_squared