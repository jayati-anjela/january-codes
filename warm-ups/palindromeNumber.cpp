class Solution {
public:
    bool isPalindrome(int x) {
        long int n = 0;
        int y=x;
        while(x!=0){
        n = (n*10)+(x%10);
        x = x / 10;
        }
        if(y < 0){
        if(y!=-n){
            return false;
        }
        else{
            return true;
        }    
        }
        else{
        if(y!=n){
            return false;
        }
        else{
            return true;
        }    
        }
        
    }
};