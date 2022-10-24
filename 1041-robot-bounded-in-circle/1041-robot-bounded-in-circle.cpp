class Solution {
public:
    bool isRobotBounded(string instructions) {
        char cur_direction = 'N';
        int x = 0 ,y=0;
        
        for(int i=0;i<instructions.length();i++){
            if(instructions[i] == 'G'){
                y += cur_direction == 'N' ? 1  : 0;
                y += cur_direction == 'S' ? -1 : 0;
                x += cur_direction == 'E' ? 1  : 0;
                x += cur_direction == 'W' ? -1 : 0;
            }
            else{
                char inc_direction = instructions[i]; // 1.L  2.R
                if(cur_direction == 'N'){
                    cur_direction = inc_direction == 'L' ? 'W' : 'E';
                }
                else if(cur_direction == 'W'){
                    cur_direction = inc_direction == 'L' ? 'S' : 'N';
                }
                else if(cur_direction == 'S'){
                    cur_direction = inc_direction == 'L' ? 'E' : 'W';
                }
                else{
                    cur_direction = inc_direction == 'L' ? 'N' : 'S';
                }
            }
        }
        
        if((x==0 && y==0) ||  cur_direction != 'N'){
            return true;
        }
        return false;
    }
};