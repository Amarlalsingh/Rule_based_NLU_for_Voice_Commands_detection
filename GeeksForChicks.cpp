#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;
//Our debugging template

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;

//LCS FUNCTION
int LCSubStr(string X, string Y, int m, int n)
{
    int LCSuff[m+1][n+1];
    int result = 0;

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i-1] == Y[j-1] || X[i-1]==Y[j-1]+32 || X[i-1]+32==Y[j-1])//32 for A,a (a-A)=32
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}

//to calculate the similarity between 2 strings
int similarity (string x, string y)
{
  return LCSubStr(x, y, x.size(), y.size());
}

vector<vector<string> > record(1000);

int main()
{
// ------------------------------------------ REFER - Comand Names -------------------------------------------------	
  vector<string> refer;
  refer.push_back("book_ticket");
  refer.push_back("CallByName");
  refer.push_back("CreateAlarmByName");
  refer.push_back("CreateAlarmWithTime");
  refer.push_back("CreateEventWithTime");
  refer.push_back("CreateEventWithTimeAndPlace");
  refer.push_back("CreateNoteWithTimeAndContent");			
  refer.push_back("DateTimeInPlace");
  refer.push_back("DateTimeNow");
  refer.push_back("RenameEvent");
  refer.push_back("SendEmail");
  refer.push_back("WeatherInCity");
  refer.push_back("WeatherTimeCity");
 cout<<"Printing refer file\n\n";
  deb(refer);
  cout<<"\n\n";
// ------------------------------------------HEADERS - Concept Headers-------------------------------------------------	
  vector<vector<string> > header(19);
  header[0].push_back("book_concept");
  header[1].push_back("call_concept");
  header[2].push_back("create_concept");
  header[3].push_back("email_concept");
  header[4].push_back("message_concept");
  header[5].push_back("name_concept");
                                                        
  header[6].push_back("search_concept");
  header[6].push_back("search");

  header[7].push_back("talk_concept");
  header[8].push_back("tell_concept");
  header[9].push_back("wake_concept");

  header[10].push_back("weather_activity");
  header[10].push_back("weather");

  header[11].push_back("what_concept");
  header[12].push_back("contact_name");
  header[13].push_back("place");
  header[14].push_back("day");
  header[14].push_back("date");
  header[15].push_back("time");

  header[16].push_back("alarm");
  header[16].push_back("alram");

  header[17].push_back("event");
  header[18].push_back("now");
//---------------------------------------------------------------------------------------------------------------------------
cout<<"Printing header file\n\n";
deb(header);
cout<<"\n\n";

  fstream filin_input[1000];
  filin_input[0].open("Concept/book_concept.txt");
  filin_input[1].open("Concept/call_concept.txt");
  filin_input[2].open("Concept/create_concept.txt");
  filin_input[3].open("Concept/email_concept.txt");
  filin_input[4].open("Concept/message_concept.txt");
  filin_input[5].open("Concept/name_concept.txt");
  filin_input[6].open("Concept/search_concept.txt");
  filin_input[7].open("Concept/talk_concept.txt");
  filin_input[8].open("Concept/tell_concept.txt");
  filin_input[9].open("Concept/wake_concept.txt");
  filin_input[10].open("Concept/weather_activity.txt");			// used different file
  filin_input[11].open("Concept/what_concept.txt");
  string line;
  for(int i=0;i<12;i++)
  {
    while (getline(filin_input[i], line))
    {
      record[i].push_back(line);
    }
  }
  filin_input[12].open("PlaceHolder/contact_name.txt");		                // used different file
  filin_input[13].open("PlaceHolder/places.txt");				//used places_edited instead of places
  while (getline(filin_input[12], line))
  {
    stringstream ss(line);
    string item;
    while (getline(ss, item,' '))
    {
      record[12].push_back(item);
    }
  
  }
  //cout<<record[12].size();
  //cout<<endl;


  while (getline(filin_input[13], line))
  {
    record[13].push_back(line);
   // cout<<line<<endl;
  }
  //cout<<record[13].size();
  //cout<<endl;

  record[14].push_back("today");
  record[14].push_back("tomorrow");
  record[14].push_back("Monday");
  record[14].push_back("Tuesday");
  record[14].push_back("Wednesday");
  record[14].push_back("Thursday");
  record[14].push_back("Friday");
  record[14].push_back("Saturday");
  record[14].push_back("Sunday");

  record[14].push_back("January");
  record[14].push_back("February");
  record[14].push_back("March");
  record[14].push_back("April");
  record[14].push_back("May");
  record[14].push_back("June");
  record[14].push_back("July");
  record[14].push_back("August");
  record[14].push_back("September");
  record[14].push_back("October");
  record[14].push_back("November");
  record[14].push_back("December");



  record[15].push_back("a.m.");
  record[15].push_back("p.m.");
  record[15].push_back("am");
  record[15].push_back("pm");
  record[15].push_back("AM");
  record[15].push_back("PM");
  record[15].push_back("Am");
  record[15].push_back("Pm");
  record[15].push_back("aM");
  record[15].push_back("pM");
  record[15].push_back("A.M.");
  record[15].push_back("P.M.");
  record[15].push_back("time");
  record[15].push_back("date");
  record[15].push_back("O clock")	;

  record[16].push_back("alarm");

  record[17].push_back("event");

  record[18].push_back("now");

  record[19].push_back("note");

cout<<"Printing record vector\n\n";
 for(int i=0;i<20;i++)
    {cout<<"index is "<<i<<endl;
        for(int j=0;j<record[i].size()-1;j++)
            cout<<record[i][j]<<", ";
        cout<<record[i][record[i].size()-1];
        cout<<endl;
    }
  fstream filin_output[1000];
  filin_output[0].open("Grammar/BookTicket.txt");
  filin_output[1].open("Grammar/CallByName.txt");
  filin_output[2].open("Grammar/CreateAlarmByName.txt");
  filin_output[3].open("Grammar/CreateAlarmWithTime.txt");
  filin_output[4].open("Grammar/CreateEventWithTime.txt");
  filin_output[5].open("Grammar/CreateEventWithTimeAndPlace.txt");
  filin_output[6].open("Grammar/CreateNoteWithNameAndContent.txt");
  filin_output[7].open("Grammar/DateTimeInPlace.txt");
  filin_output[8].open("Grammar/DateTimeNow.txt");
  filin_output[9].open("Grammar/RenameEvent.txt");
  filin_output[10].open("Grammar/SendEmail.txt");
  filin_output[11].open("Grammar/WeatherInCity.txt");
  filin_output[12].open("Grammar/WeatherTimeCity.txt");

  vector<vector<string> > rec_out(40);
  int j,len;
  for(int i=0;i<13;i++)
  {
    j=-1;
    while (getline(filin_output[i], line))
    {
      cout<<line<<endl;
      if(line.length() <= 0)
        continue;
      j++;
      rec_out[i].push_back("0000000000000000000");
      for(int k=0;k<19;k++)
      {
        for(int d=0;d<header[k].size();d++)
        {
          len=LCSubStr(line,header[k][d],line.size(),header[k][d].size());
        cout<<len<<" ";
          if(len!=header[k][d].size())
          {
            //					cout<<record[i][j]<<" "<<0<<endl;
            continue;
          }
          else
          {
            //	cout<<record[i][j]<<" "<<1<<endl; // rec_out - it is all the binary string for the individual
            //            lines in grammer file of a command
            rec_out[i][j][k]='1';
          }
        }
      }
      cout << "line = " << line << endl << "rec_out = " << rec_out[i][j] << endl;
    }
    //cout<<endl;

    for(int j=0;j<rec_out[i].size();j++)
    {
      cout<<rec_out[i][j]<<endl;
    }
    cout<<endl;
  }
	ofstream output("Testing/output0.txt");
  fstream input;
  input.open("Testing\\input.txt");
  int b=1;
  getline(input,line);
  cout<<"input_testing"<<endl;
  while (getline(input, line))
  {
    vector<pair<int,int> > answer;
    string s;
    if(line[0]=='C' && line[1]=='a' &&
        line[2]=='s' && line[3]=='e' && line[4]=='#')// CASE NUMBER INPUT
    {
      continue;
    }
    //		string word;
    //		string temp;
    //     	stringstream iss(temp);
    // 		while (iss >> word)
    //       	{
    //		 	if(word=="and")
    //		 	{
    //		 		cout<<iss;
    //			}
    //
    //		}
    s="0000000000000000000";
    cout<<"case:"<<b++<<endl;
    output<<"case:"<<b-1<<endl;
    int len;
    string t_str =line;
    for(int p=0; p<20 ; p++) {
      int max = -1;
      string max_str = "";
      int index = -1;
      for(int i=0;i < record.size();i++)
      {
        int flag=0;
        int count = 0;

        for(int j=0;j<record[i].size();j++)
        {
          len=LCSubStr(line,record[i][j],line.size(),record[i][j].size());
          //cout<<len<<" ";
          if(len!=record[i][j].size())
          {
            //					cout<<record[i][j]<<" "<<0<<endl;
            continue;
          }
          else
          {
            //					cout<<record[i][j]<<" "<<1<<endl;
            if(len > max){
              index = i;
              max_str = record[i][j];
              max = len;
            }
          }
        }
        //cout<<endl;
      }

      if(max > -1 && index > -1 && !max_str.empty()){
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        std::transform(max_str.begin(), max_str.end(), max_str.begin(), ::tolower);
        int f_index = line.find(max_str);

        if(index == 13) {
          cout << "Place : " << max_str << endl;
          output << "Place : " << max_str << endl;
        }
        if(index == 12) {
          cout << "Name : " << max_str << endl;
          output << "Name : " << max_str << endl;
        }
        if(index == 15) {
          int time_pos = line.find_last_of(" ", f_index-2);
          int offset = line.find(" ", f_index) - time_pos;
          if(!max_str.compare("o clock"))
            offset = max_str.length() + (f_index - time_pos);
          string time_str = line.substr(time_pos, offset);

          if(
              time_str.find('0') != std::string::npos ||
              time_str.find('1') != std::string::npos ||
              time_str.find('2') != std::string::npos ||
              time_str.find('3') != std::string::npos ||
              time_str.find('4') != std::string::npos ||
              time_str.find('5') != std::string::npos ||
              time_str.find('6') != std::string::npos ||
              time_str.find('7') != std::string::npos ||
              time_str.find('8') != std::string::npos ||
              time_str.find('9') != std::string::npos
            ) {
            cout << "Time : " << time_str << endl;
            output << "Time : " << time_str << endl;
          }
        }
        if(index == 14) {
            cout << "Day : " << max_str << endl;
            output << "Day : " << max_str << endl;
        }
        if(index == 16) {
          int name_indx = t_str.find("with name");
          int create_pos = -1;
          for(int j=0;j<record[2].size();j++)
          {
            len = LCSubStr(t_str, record[2][j], t_str.size(),record[2][j].size());
            if(len!=record[2][j].size())
              continue;
            else
            {
                create_pos = t_str.find(record[2][j]);
            }
          }

          if( create_pos != std::string::npos ) {
              if(name_indx != std::string::npos) {
                cout << "Alarm Name : " << t_str.substr((name_indx + 9), create_pos + 1) << endl;
                output << "Alarm Name : " << t_str.substr((name_indx + 9), create_pos + 1) << endl;
              }
              else {
                cout << "Alarm Name : " << t_str.substr(create_pos, (t_str.find("alarm") - create_pos)) << endl;
                output << "Alarm Name : " << t_str.substr(create_pos, (t_str.find("alarm") - create_pos)) << endl;
              }

          }
        }
        if(index == 19) {
          string note_name = "";
          string note_content = "";
          int idx = -1;
          if(t_str.find("note down") != std::string::npos)
            idx = t_str.find("note down") + 9;
          else if(t_str.find("note with title") != std::string::npos)
            idx = t_str.find("note with title") + 15;
          else
            idx = t_str.find("note") + 4;

          note_content = t_str.substr(idx);

          if(note_content.find(" in ") != std::string::npos ) {
            if(t_str.find("note with title") != std::string::npos) {
              note_name = note_content.substr(0, note_content.find(" and "));
              note_content = note_content.substr(note_content.find(" and ") + 5);
            } else {
              note_name = note_content.substr(note_content.find(" in ") + 4);
            }
          }

          if((note_content.find(" in ") != std::string::npos)) {
            note_content = note_content.replace(note_content.find(" in "), -1, "");
          }
          cout << "Note Name : " << note_name << endl;
          output << "Note Name : " << note_name << endl;
          cout << "Note Content : " << note_content << endl;
          output<< "Note Content : " << note_content << endl;
        }
        if(index == 17) {
          int idx_to = t_str.find(" to ");
          int idx_in = t_str.rfind(" in ");
          int offset = idx_in - idx_to;
          if(idx_to > -1){
            string target_event = t_str.substr(idx_to + 4, offset - 4);
            cout << "Target Event : " << target_event << endl;
            output << "Target Event : " << target_event << endl;
          }
        }

        if (f_index != std::string::npos) {
          line.replace(f_index, max, "");
          max = -1;
        }
        s[index]='1';
      }
    }

    // end of p loop

    line = t_str;
    cout << "line = " << line << endl;
    cout << "s = " << s << endl;

    int f=0;
    string temp=line;
    stringstream ss(temp);
    string item;

    for(int i=0; i<record[13].size(); i++)
    {
      string str=record[13][i];
      int p=line.find(str);
      if(p!=-1)
      {
        f++;
      }

    }
    if(f>1)
    {
      s[0]='1';
    }
    else
      s[0]='0';

    int flag=0;
    int sim_indx = -1;
    int final_indx = -1;
    int max_sim_index = -1;
    for(int m=0;m<rec_out.size();m++)
    {
      for(int n=0;n<rec_out[m].size();n++)
      {
        sim_indx = similarity(rec_out[m][n], s);
        if(sim_indx > max_sim_index)
        {
          final_indx = m;
          max_sim_index = sim_indx;
        }
      }
    }

    if(final_indx > -1)
    {
      cout<<refer[final_indx]<<endl;
      output<<refer[final_indx]<<endl;
  }


  }

  //end of testcase loop

  return 0;
}

