#ifndef ITEM_TYPE
#define ITEM_TYPE

class ItemType{
    public:
        int key;
        ItemType(int k = 0): key(k) {}
    
        int CompareTo(const ItemType& other) const{
            //if(key == other.key) return 0;
            //return( key < other.key)? -1 : 1;
            //expanded version below ? acts likes an if/else statement

            if(key == other.key){
                return 0;
            } else if(key<other.key){
                return -1;
            }else{
                return 1;
            }
        }
};

#endif
