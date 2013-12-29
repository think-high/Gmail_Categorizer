			///***\\\The Gmail categorizer using Naive bayes Learning technique///***\\\

Obviously you would have noticed this new Category tabs in Gmail named as Primary, Social and Promotions. This automated categorization is done by first training the machine with some training data and then cross validating the prediction to improve the accuracy. Before training few features are set and the machine is trained based on those features. The prediction also proceeds based on those features.


The Algorithm implemented in code takes raw data to learn from.It takes data in the format given below*.From the given data it makes 20% data for cross validation and remaining to generate parameters of naive bayes.Then it will ask for a input mail to predict about and it will give you the probability of each category that mail may belong.

To ease your data input part one file named as data.txt contains 150 mails from various Gmail accounts you need to just copy paste the data to your Program running console and then enter the mail you want to predict for.

*Format of data.txt.

The first line in data.txt is the no. of emails ,N . After that N mails follow, each mail is of this format:

#<space><Category><space><mail content><space>######

<Category> : “Primary” or “Social” or “Promotional”

<mail content>: this the mail content which contains alphabets , numbers, @, _  , ! ,? , $ , %,\n, <space>. 

Example:

Data.txt
5
# Primary Hi! How are you ? 
I am missing you ######
# Social You have a friend request ######
# Primary hello hi byee ######
# Promotional Special Discount for you ######
# Promotional Special offer 30% off this Diwali !! ######

After feeding the input data,it will be splitted into 80:20 ratio. 80% will be used for genetrating features and remaining 20% will be used as cross validation data for setting up the parameter of 'Laplace smoothing' (k).

After that the program will ask for your input and you need to enter your mail and end it with <space> followed by '######' without quotes(').

You will get the probability results.

For any further clarification you can mail on rahulbhojwani2003@gmail.com