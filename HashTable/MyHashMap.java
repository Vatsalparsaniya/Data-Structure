class MyHashMap {
    
    ArrayList<ArrayList<ArrayList<Integer>>> hashMap = new ArrayList<ArrayList<ArrayList<Integer>>>(1000);
    
    /** Initialize your data structure here. */
    public MyHashMap(){
        for(int i = 0; i<1000; i++){
            ArrayList<ArrayList<Integer>> to_add = new ArrayList<ArrayList<Integer>>();
            to_add.add(new ArrayList<Integer>());
            hashMap.add(to_add);
        }
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int theHash = key % 1000;
        if (hashMap.get(theHash) == null){
            hashMap.set(theHash, new ArrayList<ArrayList<Integer>>());
        }
        remove(key);       
        hashMap.get(theHash).add(new ArrayList<Integer>());
        hashMap.get(theHash).get(hashMap.get(theHash).size()-1).add(0,key);
        hashMap.get(theHash).get(hashMap.get(theHash).size()-1).add(1,value); 
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int theHash = key % 1000;
        if (hashMap.get(theHash) != null){
            System.out.println(hashMap.get(theHash));
            for (int i = 0 ; i < hashMap.get(theHash).size(); i++){
                    if (hashMap.get(theHash).get(i).size() == 2){
                        if (hashMap.get(theHash).get(i).get(0) == key){
                            return hashMap.get(theHash).get(i).get(1);
                        }
                    }
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int theHash = key % 1000;
        if (hashMap.get(theHash) != null){
            ArrayList<ArrayList<Integer>> newCell = new ArrayList<ArrayList<Integer>>();
            newCell.add(new  ArrayList<Integer>());
            for (int i = 0 ; i < hashMap.get(theHash).size(); i++){
                    if (hashMap.get(theHash).get(i).size() == 2){
                        if (hashMap.get(theHash).get(i).get(0) != key){
                            ArrayList<Integer> aCell = new ArrayList<Integer>();
                            aCell.add(hashMap.get(theHash).get(i).get(0));
                            aCell.add(hashMap.get(theHash).get(i).get(1));    
                            newCell.add(aCell);
                        }
                    }
            }
            hashMap.set(theHash, newCell);
        }
        
    }
}
