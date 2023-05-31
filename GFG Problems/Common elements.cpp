class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector <int> vect;
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k]){
                    vect.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j]){
                    i++;
                }
                else if(B[j]<C[k]){
                    j++;
                }
                else{
                    k++; 
                }
                
                while(A[i]==A[i-1]) i++;
                while(B[j]==B[j-1]) j++;
                while(C[k]==C[k-1]) k++;

            }
            if(vect.size()==0) return {-1};
            else return vect;
        }

};