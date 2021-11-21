int maxi = INT_MIN;

class Heap {
    private:
    int size;
    vector<int> elements;    
    
    int findLeft(int i){
        
        if((2*i + 1) >= size){
            return maxi;    
        }
    
        return 2*i + 1;
    }
    
    int findRight(int i){
        
        if((2*i + 2) >= size){
            return maxi;    
        }
    
        return 2*i + 2;
    }
    
    void downheapify(int node){
        
        if(node >= size){
            return;
        }
        
        auto left = findLeft(node);
        auto right = findRight(node);
        
        int getMin = node;
        
        if(left!=maxi){
            if(elements[node] < elements[left]){
                getMin = left;
            }
        }
        if(right!=maxi){
            if(elements[getMin] < elements[right]){
                getMin = right;
            }
        }
        
        if(getMin!=node){
            swap(elements[getMin], elements[node]);
            downheapify(getMin);
        }

    }
    
    void upheapify(int node){
        if(node != 0){
            int parent = (node-1)/2;
            if(elements[parent] < elements[node]){
                swap(elements[parent], elements[node]);
                upheapify(parent);
            }
            
        }
    }
    
    public:
    Heap(){
        size = 0;
    }
    
    void insert(int value){
        elements.push_back(value);
        upheapify(size);
        size += 1;
    }
    
    int top(){
        
        if(size == 0)
            return maxi;
        
        return elements[0];
    }
    
    int pop(){
        
        int topElement = top();
        
        if(topElement!=maxi){
            elements[0] = elements[size - 1];
            elements.pop_back();
            downheapify(0);
            size -= 1;
        }
        
        return topElement;
    }

};


class Solution {
    
public:
    int maxProduct(vector<int>& nums) {
        
        Heap heap = Heap();
        
        for(int i=0;i<nums.size();i++){
            heap.insert(nums[i]);
        }
        
        int ele1 = heap.pop() - 1;
        int ele2 = heap.pop() - 1;
        
        return ele1*ele2;
        
    }
};