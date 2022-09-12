Hello!

This is your introduction to all the functions of Git and GitHub you have to know in order to complete the course of the subject we are studying here!

If you have never seen Git/Github in your life, and just want to be able to put files into the databases without any learning of deeper mechanics of Git - this is your place to go!
Now, lets get to the different processes you might want to do:

          0.Creating an issue

1)On GitHub.com, navigate to the main page of the repository.

2)Under your repository name, click Issues

3)Find Big Green Button saying "New Issue"

This will be a sign that you have started  a work on some project/changed something/wanted everyone to pay attention to something. We will be able to link issues to the pull requests later. For now just write in the description of the Issue what you want to do/did/add to the specific branch

Now, leave that Issue alone, give it some time. We can edit it at any point anyways, so don't worry if you have typed domething wrong. Now to the real stuff:


          1. Adding file with your work/documentations/presentations into the Github database:

1)You need the Git programm installed on your computer. If you don't have it installed on your system, just go to https://git-scm.com/download/ and download the installation file. follow the instructions with the default settings

2)Now you have to clone the repository from the original GitHub into your system:

  2.1)Open your "Start" menu and find with search the programm named "cmd". Open it.
  
  2.2)You can now "travel" to different Directories on your hard drive by typing in "cd <path-to-the-directory-you-want-to-go>". So go to the directory in which you want the repository to be stored in. 
  (For example, "cd C:\Users\user\Documents")
  
  2.3)Now we need to get a copy of the original. We go to the page of the original Repository on GitHub and find big green button "Code". Pushing it reveals the differnt options we have for getting a copy for ourselves.
  
  2.4)We can do it in defferent ways, but the most simple is by choosing "HTTPS" option. it gived you a link which you can copy.
  
  2.5)Now back to your system. in the cmd command menu where you typed "cd" commands now consecutively type
  
    ^git clone <URL we just copied> 
  
    (creates a copy of the branch the URL of which we copied)
    
  
    ^git checkout -b <Your new branch name>
  
    (makes a new branch on the copy you have just made on your PC)
    
 3)This is where we can add all the files we want to the repository. We can open the actual repository (like "Documents") where our repository is and put in the files we want to add.
  
  Then open the cmd again and type ^git add "FILENAME" - Filename being the name of the file we want.
  
 4)Now, when we (suppposedly) are done making all the dirfferent changes to the branch we want to add, we can repost it to the GitHub as a new branch:
  
    4.1) !!WARNING!! If you have never worked with Git before, it would want you to choose your nackname and email address somewhere along the lines. Put in these commands:
  
    ^git config --global user.email "your@email.com"
  
    ^git config --global user.name "Your name"
  
    That would make your email your@email.com and your name Your name.
  
 5)Time to type different commands again!
  
            ^git commit -m "The-Commit-Name"

            (The-Commit-Name will be the name of the file with the changes you make for everyone to see)


            ^git push origin <Your new branch name>

            (THis will add the new branch you have made changes to on the GitHub)

 CONGRATULATIONS! We can now add files to the original repository. But for those changes to be accepted as the "master" branch, we need to make a Pull Request.
 
          2. Making a pull request for your branch
  
 When you go to our new branch (you can see it in the "branches" menu), you can see the big green button "Compare & pull-request". Choose it to send it for checking to different people.
 
 -At the top you will have the new name by which our repository will be called
  
 -At the "write" category you can write a description of the pull-request - what did you change, what do you want, maybe some request to the people who will check it
 
  -At the right side of the screen you can see the "Reviewers" menu. you can add different people you want to review your work on this branch here.
 
  Now the good part: you can link pull requests to the Issues.
  
  By using set words:
  
            -close

            -closes

            -closed

            -fix

            -fixes

            -fixed

            -resolve

            -resolves

            -resolved
  
  with the #number you can link pull requests to the different issues. For example
  
  Closes #1
  
  will make a connection between your pull request and the Issue number 1. It will even show up in the issue #1's "Development" menu on the right.
  
  
  After you press big green button again, pull request is made, and all the people you have assigned to it will be able to see it and leave comments on its developements
  
And That's about it! We've covered all the steps required in order to work  with GitHub's system as a storage.
Feel free to experiment with different parameters for Issues and Pull requests!

