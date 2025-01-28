# Compiler und Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Ausführbare Datei
TARGET = dungeon_rpg

# Quell- und Objektdateien
SRCS = main.cpp Game.cpp Player.cpp Monster.cpp Item.cpp Room.cpp Dungeon.cpp Bag.cpp
OBJS = $(SRCS:.cpp=.o)

# Regel für die Erstellung der ausführbaren Datei
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regel für das Kompilieren der Objektdateien
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Bereinigen von generierten Dateien
clean:
	rm -f $(OBJS) $(TARGET)
