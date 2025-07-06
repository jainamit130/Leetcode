class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaryStrings;
        for (int num : nums) {
            string binary = bitset<32>(num).to_string(); 
            binary = binary.substr(binary.find('1')); 
            binaryStrings.push_back(binary);
        }
        
        long long maxVal = 0;
        
        sort(binaryStrings.begin(), binaryStrings.end());
        do {
            string concatenatedBinary;
            for (const string& bin : binaryStrings) {
                concatenatedBinary += bin;
            }
            
            long long decimalValue = stoll(concatenatedBinary, nullptr, 2);
            
            maxVal = max(maxVal, decimalValue);
        } while (next_permutation(binaryStrings.begin(), binaryStrings.end()));
        
        return maxVal;
    }
};