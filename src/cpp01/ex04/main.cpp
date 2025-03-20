# include <iostream>
# include <fstream>

int main(int argc, char **argv) {
    
    // we only support 3 arguments.
    if (argc != 4)
    {
        std::cerr << "Only 3 parameters are allowed" << std::endl;
        return EXIT_FAILURE;
    }

    // tries to open the infile.
    std::ifstream in_file(argv[1]);
    if (!in_file)
    {
        std::cerr << "Failed to open the input file." << std::endl;
        return EXIT_FAILURE;
    }

    // read all the contents to buf.
    std::string buf;
    std::string line;
    while (std::getline(in_file, line))
        buf += line + "\n";
    in_file.close();
    
    // tries to open the outfile.
    std::string out_filename = std::string(argv[1]) + ".replace";
    std::ofstream out_file(out_filename);
    if (!out_file)
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return EXIT_FAILURE;
    }

    size_t len = std::string(argv[2]).length();
    while (true) {
        size_t pos = buf.find(argv[2]);
        if (pos == std::string::npos)
        {
            // if not found, we output the rest.
            out_file << buf;
            break;
        }
        // If found, split the string, and send the pre to output.
        auto pre = buf.substr(0, pos);
        out_file << pre << argv[3];
        buf = buf.substr(pos + len, buf.length() - pos - len);
    }
    
    out_file.close();
    return EXIT_SUCCESS;
}
