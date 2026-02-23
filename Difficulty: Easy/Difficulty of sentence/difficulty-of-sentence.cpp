int calcDiff(string str) {
    int hard = 0, easy = 0;
    
    int vowels = 0, consonants = 0;
    int consecutiveCons = 0;
    bool hasFourConsecutive = false;
    
    auto isVowel = [](char c) {
        c = tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    };
    
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == ' ') {
            
            if (vowels + consonants > 0) {
                if (hasFourConsecutive || consonants > vowels)
                    hard++;
                else
                    easy++;
            }
            
            // Reset for next word
            vowels = consonants = consecutiveCons = 0;
            hasFourConsecutive = false;
        }
        else {
            char c = tolower(str[i]);
            
            if (isVowel(c)) {
                vowels++;
                consecutiveCons = 0;
            } 
            else {
                consonants++;
                consecutiveCons++;
                
                if (consecutiveCons == 4)
                    hasFourConsecutive = true;
            }
        }
    }
    
    // Check last word
    if (vowels + consonants > 0) {
        if (hasFourConsecutive || consonants > vowels)
            hard++;
        else
            easy++;
    }
    
    return 5 * hard + 3 * easy;
}