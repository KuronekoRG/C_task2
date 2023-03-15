#include <iostream>
#include <vector>
#include <string>

class Version {
public:
    Version(int number, std::string state, std::string date) :
        number_(number), state_(state), date_(date) {}

    int getNumber() const { return number_; }
    std::string getState() const { return state_; }
    std::string getDate() const { return date_; }

private:
    int number_;
    std::string state_;
    std::string date_;
};

class File {
public:
    File(std::string name) : name_(name) {}

    void addVersion(int number, std::string state, std::string date) {
        versions_.push_back(Version(number, state, date));
    }

    std::string getName() const { return name_; }

    std::vector<Version> getVersions() const { return versions_; }

private:
    std::string name_;
    std::vector<Version> versions_;
};

class VersionControlManager {
public:
    void addFile(File file) {
        files_.push_back(file);
    }

    std::vector<File> getFilesByVersionDate(std::string date) const {
        std::vector<File> result;

        for (auto file : files_) {
            std::vector<Version> versions = file.getVersions();
            for (auto version : versions) {
                if (version.getDate() == date) {
                    result.push_back(file);
                    break;
                }
            }
        }

        return result;
    }

    std::vector<File> getFilesByVersionNumber(int number) const {
        std::vector<File> result;

        for (auto file : files_) {
            std::vector<Version> versions = file.getVersions();
            for (auto version : versions) {
                if (version.getNumber() == number) {
                    result.push_back(file);
                    break;
                }
            }
        }

        return result;
    }

    std::vector<File> getFilesByVersionState(std::string state) const {
        std::vector<File> result;

        for (auto file : files_) {
            std::vector<Version> versions = file.getVersions();
            for (auto version : versions) {
                if (version.getState() == state) {
                    result.push_back(file);
                    break;
                }
            }
        }

        return result;
    }

private:
    std::vector<File> files_;
};

int main() {
    File file1("file1");
    file1.addVersion(1, "fixed", "2023-01-06");
    file1.addVersion(2, "redacting", "2023-01-02");
    file1.addVersion(3, "fixed", "2023-01-03");

    File file2("file2");
    file2.addVersion(1, "fixed", "2023-01-01");
    file2.addVersion(2, "redacting", "2023-01-02");
    file2.addVersion(3, "redacting", "2023-01-03");

    File file3("file3");
    file3.addVersion(1, "fixed", "2022-01-01");
    file3.addVersion(2, "redacting", "2022-01-02");
    file3.addVersion(3, "redacting", "2022-01-03");

    VersionControlManager manager;
    manager.addFile(file1);
    manager.addFile(file2);
    manager.addFile(file3);

    std::cout << "Files by version date 2023-01-01:\n";
    std::vector<File> filesByVersionDate = manager.getFilesByVersionDate("2023-01-01");
    for (auto file : filesByVersionDate) {
        std::cout << file.getName() << "\n";
    }
    std::cout << "\n";

    std::cout << "Files by version number 2:\n";
    std::vector<File> filesByVersionNumber = manager.getFilesByVersionNumber(3);
    for (auto file : filesByVersionNumber) {
        std::cout << file.getName() << "\n";
    }
    std::cout << "\n";

    std::cout << "Files by version state fixed:\n";
    std::vector<File> filesByVersionState = manager.getFilesByVersionState("fixed");
    for (auto file : filesByVersionState) {
        std::cout << file.getName() << "\n";
    }
    std::cout << "\n";

    return 0;
}
