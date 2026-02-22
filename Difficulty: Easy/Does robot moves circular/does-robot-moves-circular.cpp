string isCircular(string path) {
    
    int x = 0, y = 0;
    int dir = 0;  // 0=N, 1=E, 2=S, 3=W
    
    for(char move : path) {
        
        if(move == 'G') {
            if(dir == 0) y++;       // North
            else if(dir == 1) x++;  // East
            else if(dir == 2) y--;  // South
            else x--;               // West
        }
        else if(move == 'L') {
            dir = (dir + 3) % 4;  // turn left
        }
        else if(move == 'R') {
            dir = (dir + 1) % 4;  // turn right
        }
    }
    
    if(x == 0 && y == 0)
        return "Circular";
    else
        return "Not Circular";
}