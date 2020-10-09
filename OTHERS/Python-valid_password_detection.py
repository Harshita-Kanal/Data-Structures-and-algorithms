import re

def _is_valid_password(password):
  """ Checks if a passwords is strong: 
  8 charachers long, at least 1 digit, 1 special character and 1 upper and 1 lower case character. 
  Returns False if the password is strong"""

  pass_valid = re.compile(r'((?P<digit>\d)|(?P<Special>[!@#$%^&*])|(?P<uppercase>[A-Z])|(?P<lowercase>[a-z]))*')    

  if len(password)<8: 
    print("Password must be at least 8 characters long\n")          #Check password lenght
  else:
    pass_matches = re.match(pass_valid, password)                  #Check the other requirements
    
    conditions = []                                               
    for key,item in (pass_matches.groupdict()).items():             #Group the matches in a dictionary
      if item == None:                                              #Store only the unmatched groups
        conditions.append(key)
    
    if conditions:                                                     
      print("\nPassword must include these type of characters: ")
      for condition in conditions:                                  
        print(condition )                                           #Print the requirements that are not met
    else:
      return False                                                  #If all the requieremnts are met return False
                                                                    

while True: 
  user_password = input("Enter your password: (Press 'q' to quit at any time) ")
  if user_password =='q':
    break

  valid_password = _is_valid_password(user_password)
  if valid_password == False:                               
    print("Strong password")
    break
  
