#include<iostream>   
#include<map>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

//一个案例巩固STL容器
class Worker{
    public:
    int salary;
    string name;
};

void createWorker(vector<Worker>& V){
    string nameSeed="ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        Worker W;
        W.name="员工";
        W.name+=nameSeed[i];
        W.salary=rand()%10000+10000;//10000~19999    rand()0~32767
        V.push_back(W);
    }
}

void setGroup(vector<Worker>& V,multimap<int,Worker>& MM){
    for(vector<Worker>::iterator ite=V.begin();ite!=V.end();ite++){
        int department=rand()%3;//0 1 2
        //插入分组
        MM.insert(make_pair(department,*ite));
    }
}

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

void showWorker(const multimap<int,Worker>& MM){
    multimap<int,Worker>::const_iterator CH=MM.find(CEHUA);
    multimap<int,Worker>::const_iterator MS=MM.find(MEISHU);
    multimap<int,Worker>::const_iterator YF=MM.find(YANFA);
    if(CH!=MM.end()){
        cout<<"策划部门有"<<MM.count(CEHUA)<<"人，分别为："<<endl;
        for(CH;CH!=MS;CH++){
            cout<<(*CH).second.name<<"   "<<CH->second.salary<<endl;
        }
        cout<<endl;
    }
    if(MS!=MM.end()){
        cout<<"美术部门有"<<MM.count(MEISHU)<<"人，分别为："<<endl;
        for(MS;MS!=YF;MS++){
            cout<<(*MS).second.name<<"   "<<MS->second.salary<<endl;
        }
        cout<<endl;
    }
    if(YF!=MM.end()){
        cout<<"研发部门有"<<MM.count(YANFA)<<"人，分别为："<<endl;
        for(YF;YF!=MM.end();YF++){
            cout<<(*YF).second.name<<"   "<<YF->second.salary<<endl;
        }
        cout<<endl;
    }
}

int main(){
    srand((unsigned int)time(NULL));//可以让每回随机的不一样   要加ctime头文件
    //创建员工
    vector<Worker> V;
    createWorker(V);
    // for(vector<Worker>::iterator ite=V.begin();ite!=V.end();ite++){
    //     cout<<(*ite).name<<"   "<<ite->salary<<endl;
    // }
    // cout<<endl;

    //分组
    multimap<int,Worker> MM;
    setGroup(V,MM);

    //分组显示员工
    showWorker(MM);
}










// class Compare{
//     public:
//     bool operator()(int k1,int k2){
//         return k1>k2;
//     }
// };

// void PrintM(const map<int,int,Compare>& m){
//     for(map<int,int,Compare>::const_iterator ite=m.begin();ite!=m.end();ite++){
//         cout<<(*ite).first<<","<<(*ite).second<<"   ";
//     }
//     cout<<endl;
// }

// int main(){
//     map<int,int,Compare> m;
//     m.insert(make_pair(1,4));m.insert(make_pair(5,2));m.insert(make_pair(7,1));m.insert(make_pair(3,3));
//     PrintM(m);//7,1   5,2   3,3   1,4
// }





// //插入删除
// int main(){
//     map<int,int> m;
//     //第一种插入
//     m.insert(pair<int,int>(1,10));
//     //第二种插入
//     m.insert(make_pair(2,20));
//     //第三种插入
//     m.insert(map<int,int>::value_type(3,30));
//     //第四种插入
//     m[4]=40;

//     cout<<m[4]<<endl;

//     //删除
//     m.erase(m.begin());//删除第一个
//     m.erase(3);//按照key删除
//     m.erase(m.begin(),m.end());//区间删除
    
//     //清空
//     m.clear();   
// }





// //构造
// int main(){
//     map<int,int>m;
    
//     //插入
//     m.insert(pair<int,int>(3,50));m.insert(pair<int,int>(2,20));
//     m.insert(pair<int,int>(5,30));m.insert(pair<int,int>(1,10));
//     PrintM(m);//1,10   2,20   3,50   5,30

//     //拷贝构造
//     map<int,int>m2(m);
//     PrintM(m2);

//     //operator=赋值
//     map<int,int>m3=m;
//     PrintM(m3);
// }