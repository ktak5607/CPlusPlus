#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    string quote = "What happens if I freeze? Remember to breathe";
    //create an output stream
    ofstream writer("Forbiden Kingdom Quote.txt");
    //make sure stream was created successfully
    if(!writer){
        cout<<"an error occured"<<endl;
        return -1;
    }
    //write the quote to the file, remember to close the stream when done
    else{
        writer<<quote<<endl;
        writer.close();
    }
    //create a new output stream but this time append new stuff at end (ios::app)
    //see internet for full list of ios:: options
    ofstream writer2("Forbiden Kingdom Quote.txt", ios::app);

    if(!writer2){
        cout<<"an error occured"<<endl;
        return -1;
    }
    //write the quote to the file, remember to close the stream when done
    else{
        writer2<<"\n-Jet Li"<<endl;
        writer2.close();
    }
    char letter;
    //create a new input stream
    ifstream reader("Forbiden Kingdom Quote.txt");
    if(!reader){
        cout<<"there was an error opening reader"<<endl;
        return -1;
    }
    else{
        for(int i = 0; !reader.eof(); i++){
            reader.get(letter);
            cout<<letter;
        }
        cout<<endl;
        reader.close();

    }
    

    return 0;
}
