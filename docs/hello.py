def foo():  # Missing colon here!
    c = "hello world"
    print(c)  # Use brackets for your print statements!
    i = 1
    for letter in c:
        i += 1  # Cool handy shortcut
        if i % 2 == 0:
            print(i, " * ")  # This has to be indented!
        else:
            print(i, " # ")
foo()
