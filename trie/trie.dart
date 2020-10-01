final int asize=26;

trieNode root=trieNode();

void main(){
  insert('abcdefg');
  insert('eminem');
  insert('a');
  insert('samyak');  
  insert('example');
  insert('exam');
  insert('am');
  insert('vora');
  insert('axe');
//   print(search('am'));
  List<String> letters=['a','e','x','m','p','l'];
//   getPossbleWordsFromCharacters(letters);
  autoSuggestion('a');
}

 class trieNode{
  bool end=false;
  List<trieNode> children=new List<trieNode>(asize);
}


void insert(String name){
  int length=name.length;
  trieNode crawl=root;//initially start to crawl from the root
  
  for(int height=0;height<length;height++){
    int index=name.codeUnitAt(height)-'a'.codeUnitAt(0);
    
    if(crawl.children[index]==null){//If Letter does Not match
      crawl.children[index]=trieNode();
    }
    crawl=crawl.children[index];
    
  }
  crawl.end=true;//Here the word Completes
}

bool search(String name){
  int length=name.length;
  trieNode crawl=root;
  
  for(int height=0;height<length;height++){
    int index=name.codeUnitAt(height)-'a'.codeUnitAt(0);
    
    if(crawl.children[index]==null)
      return false;
    
    crawl=crawl.children[index];
  }
  if(crawl.end==true)
      return true;
  else
      return false;
}

// Jumbled rearrange starts
void getPossbleWordsFromCharacters(List<String> letters){
  //prepare a list to check availability of characters
  List<bool> hash=List<bool>(asize);//true or null
  
  for(int i=0;i<letters.length;i++){
    hash[letters[i].codeUnitAt(0)-'a'.codeUnitAt(0)]=true;//similar to a set to check the availability
  }
  
  for(int i=0;i<asize;i++){
    if(hash[i]==true && root.children[i]!=null){//we hasve resources and branch in tree
      searchAhead(root.children[i],hash,String.fromCharCode(i+'a'.codeUnitAt(0)));
    }
  }
}

void searchAhead(trieNode spy,List<bool> hash,String name){
//   Case if the word is a subset of another word
  if(spy.end)
      print(name);
  
//   else traverse every node and check if it forms a word ahead
  for(int index=0;index<asize;index++){
    if(hash[index]==true && spy.children[index]!=null)
      searchAhead(spy.children[index],hash,name+String.fromCharCode(index+'a'.codeUnitAt(0)));
  }
}
// Jumbled rearrange ends

//Auto Suggestion Start
bool autoSuggestion(String name){
  trieNode crawl=root;
//   Case check if the given prefix is atleast existing
  int length=name.length;
  for(int height=0;height<length;height++){
    int index=name.codeUnitAt(height)-'a'.codeUnitAt(0);
    
    if(crawl.children==null)
       return false;//Prefix Not present  
    crawl=crawl.children[index];
  }
  
//   elsewise the prefix is present till here
  
 autoSuggestionGetNames(crawl,name);
  return true;  
}

void autoSuggestionGetNames(trieNode crawl,String name){
//   Case if this current word is already Complete
  if(crawl.end==true)
      print('$name');//We get the word here
  
  for(int index=0;index<asize;index++){
//     If we see a possibility in any index
    if(crawl.children[index]!=null){
      autoSuggestionGetNames(crawl.children[index],name+String.fromCharCode(index+'a'.codeUnitAt(0)));

    }
  }
}

//Auto Suggestion ends
