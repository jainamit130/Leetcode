class Solution {
    public int lengthOfLastWord(String s) {
        String lastWord="";
        String word="";
        for (int i = 0; i < s.length(); i++) {
            char ch=s.charAt(i);
            if(ch==' '){
                if(word!="")
                    lastWord=word;
                word="";
                continue;
            } else {
                word+=ch;
            }
        }
        if(word!="")
            lastWord=word;
        return lastWord.length();
    }
}