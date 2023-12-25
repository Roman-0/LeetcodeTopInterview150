def make_files(input_file):
    with open(input_file, 'r') as infile:
        lines = infile.readlines()

    # Keep only the odd lines
    for line in lines:
        number = int(line.split(" ")[0][:-1]) + 1
        name = (' '.join(line.split(" ")[1:]).strip().strip('"'))
        # print(number)
        # print(name)
        folder = "./"
        if number > 140:
            folder = "../MultidimensionalDP/"
        elif number > 135:
            folder = "../1DDP/"
        elif number > 129:
            folder = "../Math/"
        elif number > 123:
            folder = "../BitManip/"
        elif number > 119:
            folder = "../Heap/"
        elif number > 112:
            folder = "../BinarySearch/"
        elif number > 110:
            folder = "../KadanesAlgorithm/"
        elif number > 106:
            folder = "../DivideAndConquer/"
        elif number > 99:
            folder = "../Backtracing/"
        elif number > 96:
            folder = "../Trie/"
        elif number > 93:
            folder = "../GraphBFS/"
        elif number > 87:
            folder = "../Graph/"
        elif number > 84:
            folder = "../BinarySearchTree/"
        elif number > 80:
            folder = "../BinaryTreeBFS/"
        elif number > 66:
            folder = "../BinaryTree/"
        elif number > 55:
            folder = "../LinkedList/"
        elif number > 50:
            folder = "../Stack/"
        elif number > 46:
            folder = "../Intervals/"
        elif number > 37:
            folder = "../Hashmap/"
        elif number > 32:
            folder = "../Matrix/"
        elif number > 28:
            folder = "../SlidingWindow/"
        elif number > 23:
            folder = "../TwoPointers/"
        elif number > 1:
            folder = "../ArrayString/"

            # with open(folder+name.split('"')+".cpp", 'w') as outfile:
        # os.remove(folder+name+".cpp")
        with open(folder+name.replace(" ", "_") + ".cpp", 'w') as outfile:
            outfile.writelines(
                ["//Roman Olsen\n",
                 "//Leetcode top 150\n",
                 "// "+name+"\n"
                 "//\n",
                 "// To be completed\n"]
            )


inputfile = 'output.txt'

make_files(inputfile)
