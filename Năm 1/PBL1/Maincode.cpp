#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib> 
#include <fstream>
using namespace std;
const int maxuser =1000;
class user {
	friend class hoithao;
    private:
    	string tenkhach;
	    string email;
	    string sodt;

    public:
    string getTenkhach(){
    	return tenkhach;
	}
	
	string getEmail(){
		return email;
	}
	
	string getSodt(){
		return sodt;
	}
	
	void setTenkhach(string tenkhach){
		this->tenkhach=tenkhach;
		chuanhoa();
	}
	
	void setEmail(string email){
		this->email=email;
	}
	
	void setSodt(string sodt){
		this->sodt=sodt;
	}
	
    user(){
        tenkhach="";
        sodt="";
        email="";
    }
    
    user(string khachhang, string sdt, string mail ){
        tenkhach=khachhang;
        sodt=sdt;
        email=mail;
	}
	
    void nhaptt(){
        cin.ignore();
        cout<<"Ho va Ten: ";                
        getline(cin,tenkhach);
        cout<<"So dien thoai: ";            
        getline(cin,sodt);
        cout<<"Dia chi Email: ";            
        getline(cin,email);
    }
    
	void chuanhoa(){
   		string res = "";
    	stringstream ss(tenkhach);
    	string token;
    	while (ss >> token){
    		res += toupper(token[0]);
    		for (int i=1; i < token.length(); i++){
    			res += tolower(token[i]);
			}
			res += " ";
		}
		res.erase(res.length() - 1);
		tenkhach = res; 
	} 
};

class hoithao{
	friend class user;
    private:
    	string tenHT;
	    string diadiem;
	    string thoigian;
	    string IDHT;  
    public:
    int soluong;
    int soHT;
    int souser=0;
    user dsach[maxuser];
    hoithao(){
        tenHT="";
        diadiem="";
        thoigian="";
        IDHT="";
        soluong=0;
    }

    hoithao(string tenht, string dd, string TG,string ID, int SL){
        tenHT=tenht;
        diadiem=dd;
        thoigian=TG;
        IDHT=ID;
        soluong=SL; 
	}

    void setHT(){
        cin.ignore();
        cout<<"Ten hoi thao: ";         
        getline(cin,tenHT);
        cout<<"ID hoi thao: ";          
        getline(cin,IDHT);
        cout<<"Dia diem: ";             
        getline(cin,diadiem);
        cout<<"Thoi gian: ";            
        getline(cin,thoigian);
        cout<<"So luong tham gia: ";    
        cin>>soluong;       
    }
    
    void showHT(){ 
	    cout << left << setw(15) << IDHT << setw(30) << tenHT
	    		<< setw(25) << diadiem << setw(20) << thoigian << souser<<"/"<<soluong<< endl;
	}
	
	void showallHT(hoithao ds[], int soLuong){
		cout<< setw(50)<< "THONG TIN HOI THAO"<<endl;
	    cout << left <<setw(8) << "STT" << setw(15) << "ID hoi thao" << setw(30) << "Ten hoi thao"
	         << setw(25) << "Dia diem" << setw(20) << "Thoi gian to chuc" << setw(10) << "So luong"<< endl;
	    for (int i = 0; i < soLuong; i++) {
	        cout << left << setw(8) << i+1 << setw(15) << ds[i].IDHT << setw(30) << ds[i].tenHT
	        		<< setw(25) << ds[i].diadiem << setw(20) << ds[i].thoigian << ds[i].souser<<"/"<<ds[i].soluong<< endl;
		}
	}
	
    void dangkyHT(){
    	string ten, dt, mail;
    	bool a=false;
        cin.ignore();
        cout<<"Ho va Ten: ";                
        getline(cin,ten);
        cout<<"So dien thoai: ";            
        getline(cin,dt);
        cout<<"Dia chi Email: ";            
        getline(cin,mail);
        for (int i=0; i < souser; i++){
        	if (dsach[i].getEmail() == mail || dsach[i].getSodt() == dt){
        	cout << "Dang ky that bai. Email hoac So dien thoai nay da dang ky truoc do." << endl;
        	a = true;
        	break;
        	}
		}
		if (!a){
	        dsach[souser].setTenkhach(ten);
	        dsach[souser].setSodt(dt);
	        dsach[souser].setEmail(mail);
	        souser++;
	        cout << "Dang ky thanh cong." << endl;
		}
    }
    
    void dsachthamgia(){
	   	if (soluong == 0) {
	    cout << "Danh sach trong!" << endl;
	        return;
	    }
	    cout << left << setw(8) << "STT" << setw(25) << "Ho va ten"
	         << setw(35) << "Email" << setw(15) << "SDT" << endl;
	    for (int i = 0; i < souser; i++) {
	        cout << left << setw(8) << i+1 << setw(25) << dsach[i].getTenkhach() << setw(35) << dsach[i].getEmail() 
			<< setw(15) << dsach[i].getSodt()<< endl;
	    }
    }
    
    void ghiuserCSV(const string& filename, int souser) {
	    ofstream fout(filename.c_str());
	    if (!fout) {
	        cout << "Khong mo duoc file de ghi." << endl;
	        return;
	    }
	    fout << "TenKhach,SoDienThoai,Email" << endl;
	    for (int i = 0; i < souser; i++) {
	        fout << dsach[i].getTenkhach() << ","
	             << dsach[i].getSodt() << ","
				 << dsach[i].getEmail() << endl;
	    }
	    fout.close();
	    cout << "Da ghi file CSV thanh cong." << endl;
	} 
	
    void ghiHTCSV(const string& filename, hoithao ds[], int soHT) {
	    ofstream fout(filename.c_str());
	    if (!fout) {
	        cout << "Khong mo duoc file de ghi." << endl;
	        return;
	    }
	    fout << "TenHoiThao,DiaDiem,ThoiGian,IDHoiThao,SoLuong" << endl;
	    for (int i = 0; i < soHT; i++) {
	        fout << ds[i].tenHT << ","
	             << ds[i].diadiem << ","
	             << ds[i].thoigian << ","
	             << ds[i].IDHT << "," 
				 << ds[i].soluong << endl;
	    }
	    fout.close();
	    cout << "Da ghi file CSV thanh cong." << endl;
	}
	
	void docHTCSV(const string& filename, hoithao ds[], int& soHT) {
	    ifstream fin(filename.c_str());
	    if (!fin) {
	        cout << "Khong mo duoc file CSV." << endl;
	        return;
	    }
	    string line;
	    getline(fin, line);
	    while (getline(fin, line)) {
	    	bool c = false;
	        stringstream ss(line);
	        string tenHT, diadiem, thoigian, IDHT, souserStr,soluongStr;
	        getline(ss, tenHT, ',');
	        getline(ss, diadiem, ',');
	        getline(ss, thoigian, ',');
	        getline(ss, IDHT, ',');
	        getline(ss, soluongStr);
	        int soluong = stoi(soluongStr);
	        for(int i = 0;  i < soHT; i++){
        		if (ds[i].gettenHT() == tenHT){
        		c = true;
        		break;
        		}
			}
			if (!c){
	        ds[soHT] = hoithao(tenHT, diadiem, thoigian, IDHT, soluong);
	        soHT++;
			}
	    }
	    fin.close();
	    cout << "Da doc file CSV thanh cong." << endl;
	}
	
	void docUserCSV(const string& filename, hoithao& ht, int &souser) {
	    ifstream fin(filename.c_str());
	    if (!fin) {
	        cout << "Khong mo duoc file CSV." << endl;
	        return;
	    }
	    string line;
	    getline(fin, line);
		int i=souser;
	    while (getline(fin, line)) {
	        stringstream ss(line);
	        string ten, email, sdt;
	        getline(ss, ten, ',');
	        getline(ss, sdt, ',');
	        getline(ss, email);
			bool check=false;
			for(int  j=0; j<i;j++){
				if (sdt==ht.dsach[j].getSodt() || email==ht.dsach[j].getEmail()){
				check=true;
				break; 
			}}

			if(!check){
				if(i < ht.getsoluong()){
	        ht.dsach[i] = user(ten, sdt, email);
	        i++;
				}
				else{
					cout << "Qua trinh nap gian doan do hoi thao da day. Vui long kiem tra lai." << endl;
					break;
				}
			}
	    }
	    ht.souser = i;
	    fin.close();
	    cout << "Da them nguoi dung tu file CSV." << endl;
	}
	
	string gettenHT(){
        return tenHT;
    }
    
    string getdiadiem(){
        return diadiem;
    }
    
    string getthoigian(){
        return thoigian;
    }
    
    string getIDHT(){
        return IDHT;
    }
    
    int getsouser(){
        return souser;
    }
    
    int getsoluong(){
        return soluong;
    }
};

bool kiemtraQTV(){
    string us,pass;
    cin.ignore();
    cout<<"          Dang nhap"<<endl;
    cout<<"Nhap Username: ";
    getline(cin,us);
    cout<<"Nhap Password: ";
    getline(cin, pass);
    if(us=="admin"&& pass=="admin"){
        return true;
    }
    else return false;
}

int main(){
    hoithao HT[10];
    HT[0]=hoithao("Hoi thao dien tu", "54 Nguyen Luong Bang", "01/07/2025" ,"001", 100);
    HT[1]=hoithao("Hoi thao vien thong", "54 Nguyen Luong Bang", "02/07/2025" ,"002", 100);
    HT[2]=hoithao("Hoi thao may tinh", "54 Nguyen Luong Bang", "03/07/2025" ,"003", 100);
    HT[3]=hoithao("Hoi thao vi mach", "54 Nguyen Luong Bang", "04/07/2025" ,"004", 100);
	HT[0].dsach[0] = user("Nguyen Van A", "0123456789", "a.nguyen@gmail.com");
	HT[0].dsach[1] = user("Le Thi Bich", "0938765432", "bich.le@yahoo.com");
	HT[0].dsach[2] = user("Tran Van Cuong", "0987654321", "cuong.tran@outlook.com");
	HT[0].dsach[3] = user("Pham Thi Dung", "0909090909", "dung.pham@gmail.com");
	HT[0].dsach[4] = user("Vo Minh Hieu", "0977777777", "hieu.vo@gmail.com");
	HT[0].souser = 5;
	
	HT[1].dsach[0] = user("Nguyen Van A", "0123456789", "a.nguyen@gmail.com");
	HT[1].dsach[1] = user("Bui Van Khanh", "0922222222", "khanh.bui@gmail.com");
	HT[1].dsach[2] = user("Nguyen Thi Lan", "0944444444", "lan.nguyen@hotmail.com");
	HT[1].dsach[3] = user("Pham Van Minh", "0911111111", "minh.pham@gmail.com");
	HT[1].dsach[4] = user("Tran Thi Nhung", "0933333333", "nhung.tran@yahoo.com");
	HT[1].souser = 5;
	
	HT[2].dsach[0] = user("Nguyen Van A", "0123456789", "a.nguyen@gmail.com");
	HT[2].dsach[1] = user("Hoang Thi Quyen", "0901234567", "quyen.hoang@outlook.com");
	HT[2].dsach[2] = user("Nguyen Minh Sang", "0976543210", "sang.nguyen@gmail.com");
	HT[2].dsach[3] = user("Vo Thi Thanh", "0932123456", "thanh.vo@yahoo.com");
	HT[2].dsach[4] = user("Dang Van Tu", "0929090909", "tu.dang@hotmail.com");
	HT[2].souser = 5;
	
	HT[3].dsach[0] = user("Nguyen Van B", "0909123456", "b.nguyen@gmail.com");
	HT[3].dsach[1] = user("Pham Hoang Viet", "0961231234", "viet.pham@yahoo.com");
	HT[3].dsach[2] = user("Nguyen Van Xuan", "0945678901", "xuan.nguyen@outlook.com");
	HT[3].dsach[3] = user("Le Thi Yen", "0903456789", "yen.le@gmail.com");
	HT[3].dsach[4] = user("Hoang Minh Duc", "0934567890", "duc.hoang@hotmail.com");
	HT[3].souser = 5;

    string user,pass,thongtin,ten;
    int soHT=4;
    int souser=0,n,k,m,l;
    while (true){
    		cout << endl;
    		cout << "                      BAI TAP PBL1  "<<endl;
		    cout << "                   GV : Dao Duy Tuan "<<endl;
		    cout << "               CHUONG TRINH QUAN LY HOI THAO ONLINE  "<<endl;
		    cout << "                  Pham Dai Nghia 23DT_B2"<<endl;
		    cout << "                   Tran Van Tam  24DT3"<<endl;
		    cout << endl;
		    cout << "     +-------------------------------------------------+ " << endl;
		    cout << "     |    GIAO DIEN QUAN LY DANG KY HOI THAO ONLINE    | " << endl;
		    cout << "     |-------------------------------------------------| " << endl;
			cout << "     |                                                 | " << endl;
		    cout << "     |  1. Dang ky hoi thao                            | " << endl;
		    cout << "     |  2. Huy dang ky hoi thao                        | " << endl;
		    cout << "     |  3. Xem danh sach hoi thao                      | " << endl;
		    cout << "     |  4. Lich hoi thao cua ban                       | " << endl;
			cout << "     |  5. Dang nhap la QTV                            | " << endl;
			cout << "     |  0. Thoat                                       | " << endl;
			cout << "     |                                                 | " << endl;
		    cout << "     +-------------------------------------------------+ " << endl;
            cout<<" Lua chon cua ban la: ";cin>>n;
        switch(n){
            case 1:
            if(soHT==0){
                cout<<"Hien chua co hoi thao nao!"<<endl;
                break;}
            else{
            HT[0].showallHT(HT, soHT);
            cout<<"Chon hoi thao ban muon dang ky: "; cin>>k;
            if(k>(soHT) || k<=0){
            cout<<"Khong hop le!"<<endl;
            }
            else if( HT[k-1].getsouser() == HT[k-1].getsoluong())
            cout<<"Hoi thao da day"<<endl;
            else{
               	HT[k-1].dangkyHT();
            	}
			}
            break;

            case 2:
            if(soHT==0){
                cout<<"Hien chua co hoi thao nao!"<<endl;
                break;
			}
            else{
            HT[0].showallHT(HT, soHT);
        	}
            cout<<"Chon hoi thao ban muon huy dang ky: "; cin>>k;
            if(k>(soHT) || k<=0){
            cout<<"Khong hop le!"<<endl;
            }
			cin.ignore();
            cout << "Nhap email hoac so dien thoai: ";
            getline(cin, thongtin);
            for (int i = 0; i < HT[k-1].getsouser(); i++) {
                if (HT[k-1].dsach[i].getEmail() == thongtin || HT[k-1].dsach[i].getSodt() == thongtin) {  
                    for (int j= i; j < HT[k-1].souser-1; j++){
                    	HT[k-1].dsach[j] = HT[k-1].dsach[j+1];
					}	
					HT[k-1].souser--;
					cout << "Da xoa thanh cong." << endl;
					break;
            	}
			}
            break;
            
			case 3:
            if(soHT==0)
                cout<<"Chua co hoi thao nao"<<endl;
            else{
            HT[0].showallHT(HT, soHT);}
            break;

            case 4:{
            	bool check = false;
                cin.ignore();
                cout << "Nhap email hoac so dien thoai: ";
                getline(cin, thongtin);
                for (int i = 0; i < soHT; i++) {
                    for (int j = 0; j < HT[i].souser; j++) {
                        if (HT[i].dsach[j].getEmail() == thongtin || HT[i].dsach[j].getSodt() == thongtin) {
							check=true;
                            break;
                        }
                    }
                }
                if (!check) cout << "Ban chua dang ky hoi thao nao" << endl;
                else {
	                cout << endl  << "Ban da dang ky hoi thao:" << endl;
					cout << left << setw(15) << "ID hoi thao" << setw(30) << "Ten hoi thao"
	        			 << setw(25) << "Dia diem" << setw(20) << "Thoi gian to chuc" << setw(10) << "So luong"<< endl;
	                for (int i = 0; i < soHT; i++) {
	                    for (int j = 0; j < HT[i].souser; j++) {
	                        if (HT[i].dsach[j].getEmail() == thongtin || HT[i].dsach[j].getSodt() == thongtin) {
								HT[i].showHT();
	                            break;
	                        }
	                    }
	                }                	
				}
            break;
        	}
        	
            case 5:
            if(kiemtraQTV()){
                bool run=true;
                while (run){
                		cout << "                      BAI TAP PBL1  "<<endl;
					    cout << "                   GV : Dao Duy Tuan "<<endl;
					    cout << "               CHUONG TRINH QUAN LY HOI THAO ONLINE  "<<endl;
					    cout << "                  Pham Dai Nghia 23DT_B2"<<endl;
					    cout << "                   Tran Van Tam  24DT3"<<endl;
					    cout << endl;
					    cout << "     +-------------------------------------------------+ " << endl;
					    cout << "     |    GIAO DIEN QUAN LY DANG KY HOI THAO ONLINE    | " << endl;
					    cout << "     |-------------------------------------------------| " << endl;
					    cout << "     |                                                 | " << endl;
					    cout << "     |                  Xin chao QTV                   | " << endl;
						cout << "     |                                                 | " << endl;
					    cout << "     |  1. Them hoi thao                               | " << endl;
					    cout << "     |  2. Sua hoi thao                                | " << endl;
					    cout << "     |  3. Xoa hoi thao                                | " << endl;
					    cout << "     |  4. Xem danh sach hoi thao                      | " << endl;
						cout << "     |  5. Xem danh sach tham gia                      | " << endl;
						cout << "     |  6. Ghi thong tin hoi thao ra file CSV          | " << endl;
						cout << "     |  7. Ghi thong tin user ra file CSV              | " << endl;
						cout << "     |  8. Doc thong tin hoi thao tu file CSV          | " << endl;
						cout << "     |  9. Doc thong tin user tu file CSV              | " << endl;
						cout << "     |  10. Dang xuat                                  | " << endl;
						cout << "     |  0. Thoat                                       | " << endl;
						cout << "     |                                                 | " << endl;
					    cout << "     +-------------------------------------------------+ " << endl;
                    cout<<" Lua chon cua ban la: ";cin>>n;
                    switch(n){
                        case 1:
                            HT[soHT].setHT();
                            soHT++;
                        break;

                        case 2:
						if(soHT==0)
                            cout<<"Chua co hoi thao nao"<<endl;
							else{
                            HT[0].showallHT(HT, soHT);
                            int q;
                            cout<<"Chon hoi thao ban muon sua: "; cin>>q;
                            if(q<=0 || q>(soHT)) 
                            cout<<"Khong hop le!"<<endl;
                            else
                            HT[q-1].setHT();
							}
                        break;

                        case 3:
                            int e;
                            if(soHT==0)
                            cout<<"Chua co hoi thao nao"<<endl;
                            else {
	                            HT[0].showallHT(HT, soHT);
	                            cout<<"Chon hoi thao ban muon xoa: "; cin>>e;
	                            if(e>=1 && e<=soHT){
	                            for(int i=e-1;i<(soHT-1);i++){
	                            HT[i]=HT[i+1]; }
	                            soHT--;
								cout << "Da xoa thanh cong." << endl;}
	                            else cout<<"Lua chon khong hop le!"<<endl;
        					}
                        break;

                        case 4:
                            if(soHT==0)
                            cout<<"Chua co hoi thao nao!";
                            else{
                            HT[0].showallHT(HT, soHT);
                            }
                        break;

                        case 5:
                            HT[0].showallHT(HT, soHT);
                            cout<<"Chon hoi thao ban muon xem: "; cin>>m;
                            if(m<=0 || m>soHT){
                                cout<<"Hoi thao khong ton tai!"<<endl;
                                break;
                            }
                            if( ( HT[m-1].getsouser())==0)
                            cout<<"Chua co nguoi tham gia"<<endl;
                            else{
                                cout<<"Danh sach tham gia: " <<HT[m-1].gettenHT()<<endl;
                                HT[m-1].dsachthamgia();}
                        break;
                        
                        case 6: {
						    cout << "Nhap ten file CSV de ghi (vi du: data.csv): ";
						    string tenfile;
						    cin >> tenfile;
						    HT[0].ghiHTCSV(tenfile,HT, soHT);
						    break;
						}
						
                        case 7: {
                            if(soHT==0)
                            cout<<"Chua co hoi thao nao!";
                            else{
                            HT[0].showallHT(HT, soHT);
                            }  
							cout<<"Chon hoi thao ban muon ghi: "; cin>>l;
                            if(l<=0 || l>soHT){
                                cout<<"Hoi thao khong ton tai!"<<endl;
                                break;
                            }							                      	
						    cout << "Nhap ten file CSV de ghi (vi du: data.csv): ";
						    string tenfile;
						    cin >> tenfile;
						    HT[l-1].ghiuserCSV(tenfile,HT[l-1].souser);
						    break;
						}
						
						case 8: {
							cout << "Nhap ten file CSV de nhap (vi du: data.csv): ";
						    string tenfile;
						    cin >> tenfile;
							HT[0].docHTCSV(tenfile, HT, soHT);
							break;
						}
						
						case 9: {
							if(soHT==0)
                            cout<<"Chua co hoi thao nao!";
                            else{
                            HT[0].showallHT(HT, soHT);
                            }  
							cout<<"Chon hoi thao ban muon nhap du lieu: "; cin>>l;
                            if(l<=0 || l>soHT){
                                cout<<"Hoi thao khong ton tai!"<<endl;
                                break;
                            }					
							if(HT[l-1].souser==HT[l-1].soluong){
								cout<<"Hoi thao da day!"<<endl;
								break;
							}
							cout << "Nhap ten file CSV de nhap (vi du: data.csv): ";
						    string tenfile;
						    cin >> tenfile;
							HT[0].docUserCSV(tenfile, HT[l-1], HT[l-1].souser);
							break;
						}
              
                        case 0:
                        return 0;

                        case 10:
                        	run=false;
                       		break;
                        default:
                        	cout<<"Lua chon khong hop le!"<<endl;
                        	break;
                    }
                }
            }
            else cout<<"Dang nhap that bai"<<endl;
            break;
            
            default:
            	cout<<"khong hop le!"<<endl;
            	break;

            case 0:
            	return 0;
        }
    };
}
