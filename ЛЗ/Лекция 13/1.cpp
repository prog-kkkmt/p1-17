 #include <iostream>

using namespace std; 

class CPoint{ 
protected:
        int x;                                
        int y;                                 
public:
        void SetX(int _x){
		x = _x;
	} 
         
        void SetY(int _y){
        	y=_y;
        } 
        
        int GetX(){
        	return x;
        }   
        
        int GetY(){
        	return y;
            
        }                                       
};                         

class CCircle: public CPoint{                      
protected:                 
	int r;                                         
public:                            
        void SetR(int _r){
		r=_r;
	}                                            
        int GetR(){
		return r;
	}                                        
            
};          

int main(){
	CPoint A;             
	A.SetX(3);         
	A.SetY(7);
        
	cout << "Tochka: " << A.GetX() <<" ," << A.GetY() << endl ;
   
	CCircle B;    
	B.SetY(20);       
    
	cout << "Okrugnost "<< B.GetX() <<" ," << B.GetY()<< ", " << B.GetR();
    
	return 0;
}
