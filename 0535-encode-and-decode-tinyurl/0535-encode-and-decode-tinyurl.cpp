class Solution {
public:
    unordered_map<string,string> encodemp;
    unordered_map<string,string> decodemp;
    int hash=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodemp.find(longUrl)!=encodemp.end())
            return encodemp[longUrl];
        string str=to_string(hash);
        encodemp[longUrl]=str;
        decodemp[str]=longUrl;
        hash++;
        return encodemp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodemp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));