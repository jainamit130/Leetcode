class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> original_arr(arr);
        vector<string> output;

        //1) Sort the original array of strings. 
        sort(arr.begin(), arr.end());
        
        //2) Create a set that will  that are substrings of other strings
        unordered_set<string>complete_substrings;
        
        //3) Iterate throught arr and remove words that are complete substrings of each other. 
        int n = arr.size()-1;
        for(int i = 0; i<arr.size()-1; ++i){
            //4) We need to make sure that the shorter of the 
            //   two strings is the substring being searched
            string smaller = "";
            int smaller_index = 0;
            string bigger = "";
            int bigger_index = 0;
            
            if(arr[i+1].size() > arr[i].size()){
                bigger = arr[i+1];
                bigger_index = i+1;
                smaller = arr[i];
                smaller_index = i;
            }else{
                smaller = arr[i+1];
                smaller_index = i+1;
                bigger = arr[i];
                bigger_index = i;
            }
            if(bigger.find(smaller) != string::npos){
                complete_substrings.insert(smaller);
                arr.erase(arr.begin() + smaller_index);
                n--;
                i--;
            }
        }
        
        //5) Iterate through the original array. 
        //   If the word is a complete substring of another word, we push "" to the output vector
        //   If not, we call the findAnswer helper function
        for(int i = 0; i<original_arr.size(); ++i){
            if(complete_substrings.contains(original_arr[i])){
                output.push_back("");
            }else{
                string result = findAnswer(original_arr[i], i, original_arr);
                output.push_back(result);
            }
        }
    
        return output;
        
    }
    
    //Helper function which returns the lexi smallest substring that is uncommon 
    string findAnswer(string& word, int index, vector<string>& validWords){
        //1) Create a variable that keeps track of the substring length we are looking for
        int current_length = 1;
        vector<string> output;
        
        //2) We iterate until we find a substring that is equal to current_length. 
        //   current_length starts at 1 and increments to ensure that the substrings we find are the
        //   shortest possible uncommon substrings 
        while(output.empty()){
            //3) create all substrings of word that is of the current_length 
            for(int i = 0; i<word.size(); ++i){
                if(i+current_length > word.size()){
                    break;
                }
                string substring = word.substr(i, current_length);

                //4) Iterate through all the other words and check if the current substring is uncommon
                bool found = false;
                for(int j = 0; j<validWords.size(); ++j){
                    if(index != j){
                        if(validWords[j].find(substring) != string::npos){
                            found = true;
                            break; 
                        }
                    }
                }
                if(found == false){
                    output.push_back(substring);
                }
            }
            
            
            current_length++;
            if(output.empty() && current_length > word.size()){
                return "";
            }
        }
        //5) Sort the output vector because we need the substring that is the shortest and lex smallest
        //Note that output will only contain substrings of the same length.
        sort(output.begin(), output.end());
        return output[0];
        
    }
};