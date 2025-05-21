The commands git add --all and git add . are very similar, but there is a subtle difference:

git add .
Stages new and modified files in the current directory and all subdirectories.
Does not stage deleted files outside the current directory (it only stages deletions inside the current directory and below).
git add --all
Stages all changes (new, modified, and deleted files) in the entire repository, regardless of your current directory.
Equivalent to git add -A.
In summary:

Use git add . to stage changes in the current directory and below.
Use git add --all to stage all changes (including deletions) everywhere in your repository.
For most cases, git add --all (or git add -A) is safer if you want to make sure all changes are staged.