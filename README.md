# Rule-Based-NLU-for-Voice-Commands-Detection-
This is a rule based approach for Natural Language Understanding (NLU) for Voice Commands detection for Voice Assistants.

This is an approach for the solution of problem statement given by Samsung R&D Institute Bangalore during Build a Bit at IIT(ISM) Dhanbad.

In this problem, various concept and grammar files were given and rules for each commands were given and we had to come up with an approach to detect the commands from the input sentence given by the user.For more detailed explanation of problem statement, refer to Samsung Problem statement1.doc and Samsung Problem statement1.doc files.

Our Approach - 
We basically used a binary string matching approach to detect the commands.We preprocessed all the grammar files of the various commands by making binary strings for each grammer of the commands given. We made binary strings on the basis of which concept/placeholder is present there in that grammar of that specific command.Then, we created binary string for the input command by scanning the concepts given in grammar and matched with all the binary strings for all the commands and select that command which has the most match.
Exact match is not required as we are following a probabilistic approach and trying to find that command which has the most match.

After detecting the commands from input sentences given by the user we need to extract important features(open phrases).from the sentence,which was the second part of the challenge.Kindly refer to Samsung Problem statement2.doc for detailed explanation of the problem.
