#include<vector>
#include<queue>
#include <map>
#include <string>
#include <iostream>
using namespace std;



class Solution {
    public:
        int v;
        bool path = false;
        map<string, vector<pair<string, double>>> mp;
        map<string, bool> visited;
        vector<double> result;
       void addEdge(string src, string des, double w) {
        mp[src].push_back(make_pair(des,w));       

    }
    
       
     void dfs(string src, string des,  double r) {
    
        std::vector<pair<string,double>> e = mp[src];
        
        visited[src] = true;
        
        for (auto element : e) {
           if(path)
            return;
            if ((element.first) == des){
                result.push_back(element.second*r);
                path = true;
              
                return ;
             }
             
    
             else if (!visited[element.first]){
                    
                    dfs(element.first, des,element.second*r);

            }   
            //visited = false and no element left so we return -1.0  that means every visited should be true
            // no path between these vertices
     }
            
        
    
         
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<string> nameOfNodes;
        bool srcb = false , desb = false;
        //Graph g;
        for (int i = 0; i < equations.size(); i++) {
            srcb = false , desb = false;
            addEdge(equations[i][0], equations[i][1], values[i]);
            visited.insert(make_pair(equations[i][0], false));
            visited.insert(make_pair(equations[i][1],false));
            //reverse edge 1/
            addEdge(equations[i][1], equations[i][0], 1 / values[i]);
      
            for(int j =0; j<nameOfNodes.size();j++){
      
                if(equations[i][0] ==nameOfNodes[j])
                    //it has been added befor 
                   srcb = true;
                if(equations[i][1] == nameOfNodes[j])
                    desb = true;
        }
            if(!srcb)
                nameOfNodes.push_back(equations[i][0]);
            if(!desb)
                nameOfNodes.push_back(equations[i][1]);
   
       
      
    }
       
      
      for (int i = 0; i < queries.size(); i++) {
            srcb = false;
            desb = false;
            string src = queries[i][0];
            string des = queries[i][1];
            
  
            for(int j =0 ;j<nameOfNodes.size();j++){
                
                if((nameOfNodes[j] == src))
                    srcb = true;
                if(nameOfNodes[j] == des)
                    desb = true;

            }
            
            if(srcb and desb){
            
                if (!(src == des)){
                     dfs(src, des,1);
                    
                    if (!path)
                       result.push_back(-1.0);
                    path = false;
                    for(int i = 0 ; i< nameOfNodes.size();i++){

                    
                  std::map<string, bool>::iterator it = visited.find(nameOfNodes[i]);    
                    if (it != visited.end())
                      it->second = false;
                    }
        
           }
                else{
        
                    result.push_back(1.0);
                }
                
            }    
            else
            {
                result.push_back(-1.0);
            }
                

        

    return result;

}
};
