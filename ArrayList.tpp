    
    //template file
    template <class item_t>
    ArrayList<item_t>::ArrayList(){
        capacity = 10;
        size = 0;
        items = new item_t[10];
    }
    template <class item_t>
    ArrayList<item_t>::ArrayList(int capacity){
        size = 0;
        //int capacity1 = capacity;
        items = new item_t[capacity];
        this->capacity = capacity;
    }
    template <class item_t>
    ArrayList<item_t>::~ArrayList(){
         delete[] items;
     }

    template <class item_t>
    void ArrayList<item_t>::pushBack(const item_t& item){
        if(size == 0){
            items[0] = item;
        }
        items[size+1] = item;
        size += 1; 
    }
    
    template <class item_t>
    void ArrayList<item_t>::popBack(){
        size -= 1;
    }

    template <class item_t>
    const item_t& ArrayList<item_t>::getBack() const{
        item_t& T1= items[size-1];
        return T1;
    }

    template <class item_t>
    void ArrayList<item_t>::pushFront(const item_t& item){  //items in items[] are not in the temp array.
        size +=1;
        if(size >= capacity){
            item_t* temp = new item_t[capacity*2];
            for(int i = 0; i < size; i++){
                temp[i] = items[i];
            }
            capacity = capacity*2;
            items = temp;
        }
        for(int i = size-1; i >= 1; i--){
            items[i] = items[i-1];
        }
        items[0] = item;
    }
    
    template <class item_t>
    void ArrayList<item_t>::popFront(){  
        for(int i = 1; i < size; i++){
            items[i-1] = items[i];
        }
        size -= 1;
     }

     template <class item_t>
     const item_t& ArrayList<item_t>::getFront() const{
         item_t& T1 = items[0];
         return T1;
     }

     template <class item_t>
     const item_t& ArrayList<item_t>::getItem(int index) const{
        //  item_t& T = items[index];
        //  return T;
        return items[index];
     }

     template <class item_t>
     void ArrayList<item_t>::setItem(int index, const item_t& item){
         items[index] = item;
     }

     template <class item_t>
     void ArrayList<item_t>::insert(int index, const item_t& item){
         if(index == size){
            items[size+1] = item;
            size += 1; 
         }
         else{
             size += 1;
             for(int i = size; i >= index; i--){
                 items[i] = items[i-1];
             }
             items[index] = item;
         }
     }

     template <class item_t>
     void ArrayList<item_t>::remove(int index){
         if(index == size){
             size -= 1;
         }
         else{
             for(int i = index; i < size; i ++){  //or size-1!!!
                items[i] = items[i+1];
             }
             size -= 1;
         }
     }

     template <class item_t>
     int ArrayList<item_t>::getSize() const{
         return size;
     }

     template <class item_t>
     bool ArrayList<item_t>::isEmpty() const{
         if(size == 0){
             return true;
         }
         return false;
     }

     template <class item_t>
     int ArrayList<item_t>::getCapacity() const{
         return capacity;
     }



