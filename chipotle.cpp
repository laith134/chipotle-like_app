//Name: Laith Marzouq
//ID#: 1001586886
#include <iostream>
#include	<vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Delivery{

public:
    Delivery(string fullname)
    {
      ofstream write;
      string name;
      write.open("drivers.txt", ios::app);
      if (!write.is_open())
      {
          cout << "Unable to open file";
          exit(1); // terminate with error
      }
      write << fullname<<endl;
      stringstream ss(fullname);
      getline(ss, name, ' ');
      cout<<"Newest delivery person: "<< name <<endl;
    }
    Delivery()
    {

    }
    string get_driver()
    {
        ifstream inFile; //file object created from the ifstream class
        string line;
        inFile.open("drivers.txt");
        if (!inFile.is_open())
        {
            cout << "Unable to open file"<< endl;
            exit(1); // terminate with error
        }
        getline(inFile,line); //using getline to read in whole line
        vector<string> v_answer;
        stringstream s(line);
        string tok;
        while(getline(s, tok, ' '))
        {
          v_answer.push_back(tok);
        }
        inFile.close();
        return v_answer[0];
    }

};


class Order{
      string type;
      float meal_cost;
      float delv_cost=0;

public:
      vector<std::string> v_answer;
      Order(string type)
      {
           bool check=true;
           while(check)
           {
                if(type=="Burrito" || type=="burrito")
                {
                    cout<<"Price will be $6.75"<< endl;
                    meal_cost=6.75;
                    check=false;
                }
                else if(type=="Bowl" || type=="bowl")
                {
                    cout<<"Price will be $7.25"<< endl;
                    meal_cost=7.25;
                    check=false;
                }
                else
                {
                    cout<<"Didnt pick burrito or bowl"<< endl;
                    cout<<"\n\nPlace your order:"<< endl;
                    cout<<"Burrito or Bowl?"<< endl;
                    cin>>type;
                    cin.ignore();
                }
            }
            this->type=type;
            string line;
            cout<<"Pick: chicken, streak, barbacoa.(separate chooses with ,'s no spaces)"<< endl;
            getline(cin,line);
            stringstream ss(line);
            string tok;
            while(getline(ss, tok, ','))
            {
              v_answer.push_back(tok);
            }
            if(v_answer.size()==1)
            {
                  cout<<"Pick: Tomato salsa, Corn, Guacamole (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s1(line);
                  while(getline(s1, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
            }
            else if(v_answer.size()==2)
            {
                  cout<<"Pick: Tomato salsa, Corn, Guacamole (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s1(line);
                  while(getline(s1, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
                  cout<<"Pick: Fajita veggies, Sour cream, Lettuce (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s2(line);
                  while(getline(s2, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
            }
            else if(v_answer.size()==3)
            {
                  cout<<"Pick: Tomato salsa, Corn, Guacamole (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s1(line);
                  while(getline(s1, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
                  cout<<"Pick: Fajita veggies, Sour cream, Lettuce (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s2(line);
                  while(getline(s2, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
                  cout<<"Cheese, Tomatillo-green chili salsa, Tomatillo-red chili salsa (separate chooses with ,'s no spaces)"<< endl;
                  getline(cin,line);
                  stringstream s3(line);
                  while(getline(s3, tok, ',') && tok!="none")
                  {
                    v_answer.push_back(tok);
                  }
            }
            else
            {
                cout<<"you can only pick 3 max!!!"<< endl;
                return;
            }
            cout<<"Confirm order (yes or no):"<< endl;
            cout<<type<< ": ";
            int i;
            for(i=0;i<(v_answer.size()-1);i++)
            {
                cout<<v_answer[i]<< ", ";
            }
            cout<<v_answer[i]<<endl;
            getline(cin,line);
            if(line=="No"|| line=="no")
            {
                cout<< "restarting...\n\n"<<endl;
            }
            else
            {
                Delivery d1;
                line=d1.get_driver();
                delv_cost=4.00;
                cout<< "Ok, "<< line << " will be delivering your order.Thank you" <<endl;

            }


        }
        float get_cost()
        {
 	          return delv_cost;
        }
        string get_type()
        {
 	          return type;
        }
};


int main(int argc, char **argv)
{
    int num;
    bool check=true;
    float total=0;
    string answer;
    cout << "*****Ronnie's Delivery Service*****" << endl;
    while(check)
    {
        cout<< "\n" << "______________________________" << endl;
        cout<< "Pick from the folllowing menu:"<<"\n1. Customer"<< "\n2. Apply" << "\n3. Exit" <<endl;
        cin >> num;
        if(num ==1)
        {
            cout<<"Place your order:"<< endl;
            cout<<"Burrito or Bowl?"<< endl;
            cin>>answer;
            cin.ignore();
            Order o1(answer);
            total=total+o1.get_cost();
        }
        else if(num==2)
        {
            cout<<"Enter you full name:";
            cin.ignore();
            getline(cin,answer);
            Delivery d0(answer);

        }
        else if(num==3)
        {
            cout<< "Exiting"<<endl;
            ofstream write;
            write.open("money.txt", ios::app);
            write << "$" << total<< endl;
            cout<< "Total made: $"<< total<<endl;
            check=false;
        }
        else
        {
            cout<< "Not valid entry!!! Try again.\n"<<endl;
        }

    }
    return 0;
}
