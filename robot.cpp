#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// This function reads the data from the file and stores it in a vector
vector<double> read_data(string filename) {
  vector<double> data;
  ifstream infile(filename);
  string line;
  while (getline(infile, line)) {
    data.push_back(stod(line));
  }
  infile.close();
  return data;
}
// This function calculates the moving average of the data
vector<double> moving_average(vector<double> data, int window_size) {
  vector<double> moving_average;
  for (int i = 0; i < data.size() - window_size + 1; i++) {
    double sum = 0;
    for (int j = i; j < i + window_size; j++) {
      sum += data[j];
    }
    moving_average.push_back(sum / window_size);
  }
  return moving_average;
}
// This function calculates the exponential moving average of the data
vector<double> exponential_moving_average(vector<double> data, double alpha) {
  vector<double> ema;
  ema.push_back(data[0]);
  for (int i = 1; i < data.size(); i++) {
    ema.push_back(alpha * data[i] + (1 - alpha) * ema[i - 1]);
  }
  return ema;
}
// This function calculates the Bollinger bands of the data
vector<double> bollinger_bands(vector<double> data, int window_size, double k) {
  vector<double> moving_average = moving_average(data, window_size);
  vector<double> standard_deviation = moving_average(data, window_size);
  for (int i = 0; i < data.size() - window_size + 1; i++) {
    standard_deviation.push_back(0);
  }
  for (int i = window_size; i < data.size(); i++) {
    double sum = 0;
    for (int j = i - window_size + 1; j < i + 1; j++) {
      sum += pow(data[j] - moving_average[i - window_size], 2);
    }
    standard_deviation[i] = sqrt(sum / window_size);
  }
  vector<double> upper_band;
  vector<double> lower_band;
  for (int i = 0; i < data.size(); i++) {
    upper_band.push_back(moving_average[i] + k * standard_deviation[i]);
    lower_band.push_back(moving_average[i] - k * standard_deviation[i]);
  }
  return upper_band;
}
// This function plots the data
void plot_data(vector<double> data, vector<double> upper_band, vector<double> lower_band) {
  // Create the plot
  cout << "Creating the plot..." << endl;
  cout << "Please wait..." << endl;
  
  // Set the title
  cout << "Setting the title..." << endl;
  cout << "Please wait..." << endl;
  
  // Set the x-axis label
  cout << "Setting the x-axis label..." << endl;
  cout << "Please wait..." << endl;
  
  // Set the y-axis label
  cout << "Setting the y-axis label..." << endl;
  cout << "Please wait..." << endl;
  
  // Create the plot
  cout << "Creating the plot..." << endl;
  cout << "Please wait..." << endl;
  
  // Save the plot
  cout << "Saving the plot..." << endl;
  cout << "Please wait..." << endl;
}
int main() {
  // Read the data from the file
  vector<double> data = read_data("data.csv");
  
 .push_back(0);
  }
  for (int i = window_size; i < data.size(); i++) {
    double sum = 0;
    for (int j = i - window_size + 1; j < i + 1; j++) {
      sum += pow(data[j] - moving_average[i - window_size], 2);
    }
    standard_deviation[i] = sqrt(sum / window_size);
  }
  vector<double> upper_band;
  vector<double> lower_band;
  for (int i = 0; i < data.size(); i++) {
    upper_band.push_back(moving_average[i] + k * standard_deviation[i]);
    lower_band.push_back(moving_average[i] - k * standard_deviation[i]);
  }
  return upper_band;
}
// This function calculates the RSI of the data
double rsi(vector<double> data, int window_size) {
  vector<double> up_moves;
  vector<double> down_moves;
  for (int i = 0; i < data.size() - window_size + 1; i++) {
    up_moves.push_back(0);
    down_moves.push_back(0);
  }
  for (int i = window_size; i < data.size(); i++) {
    if (data[i] > data[i - 1]) {
      up_moves.push_back(data[i] - data[i - 1]);
      down_moves.push_back(0);
    } else if (data[i] < data[i - 1]) {
      up_moves.push_back(0);
      down_moves.push_back(data[i - 1] - data[i]);
    } else {
      up_moves.push_back(0);
      down_moves.push_back(0);
    }
  }
  vector<double> avg_up_moves = moving_average(up_moves.push_back(0);
  }
  for (int i = window_size; i < data.size(); i++) {
    double sum = 0;
    for (int j = i - window_size + 1; j < i + 1; j++) {
      sum += pow(data[j] - moving_average[i - window_size], 2);
    }
    standard_deviation[i] = sqrt(sum / window_size);
  }
  vector<double> upper_band;
  vector<double> lower_band;
  for (int i = 0; i < data.size(); i++) {
    upper_band.push_back(moving_average[i] + k * standard_deviation[i]);
    lower_band.push_back(moving_average[i] - k * standard_deviation[i]);
  }
  return upper_band;
}
// This function calculates the RSI of the data
double rsi(vector<double> data, int window_size) {
  vector<double> up_moves;
  vector<double> down_moves;
  for (int i = 0; i < data.size() - window_size + 1; i++) {
    up_moves.push_back(0);
    down_moves.push_back(0);
  }
  for (int i = window_size; i < data.size(); i++) {
    if (data[i] > data[i - 1]) {
      up_moves.push_back(data[i] - data[i - 1]);
      down_moves.push_back(0);
    } else if (data[i] < data[i - 1]) {
      up_moves.push_back(0);
      down_moves.push_back(data[i - 1] - data[i]);
    } else {
      up_moves.push_back(0);
      down_moves.push_back(0);
    }
  }
  vector<double> avg_up_moves = moving_average(up_moves
  }
  return bollinger_bands;
}
// This function calculates the last digit of a number
int last_digit(double number) {
  return (int) number % 10;
}
// This function executes a trade according to the prediction
void execute_trade(double price, int prediction) {
  if (prediction == 0) {
    cout << "Buying at $" << price << endl;
  } else {
    cout << "Selling at $" << price << endl;
  }
}
int main() {
  string filename = "data.txt";
  int window_size = 10;
  double alpha = 0.2;
  double k = 2;
  vector<double> data = read_data(filename);
  vector<double> moving_average = exponential_moving_average(data, alpha);
  vector<double> bollinger_bands = bollinger_bands(data, window_size, k);
  int prediction = last_digit(moving_average.back()) % 2;
  double price = data.back();
  execute_trade(price, prediction);
  return 0;
}