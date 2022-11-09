#include <iostream>
using namespace std;

class MHS{
  //
  private:
  string MHSname;

  //Data member
  public:
  //Member Function()
  void inputname(string nama){
    MHSname = nama;
  }
  void printname(){
    cout << "Nama mahasiswa : " << MHSname << endl;
  }
};

int main(){
    //Declare an object 
    MHS mhs1, mhs2;
    mhs1.inputname("Arkan");
    mhs2.inputname("Denny");
    //cin >> mhs1.MHSname;
    //mhs1.MHSname = "Rahmat Budi";
    mhs1.printname();
    mhs2.printname();
    return 0;
}