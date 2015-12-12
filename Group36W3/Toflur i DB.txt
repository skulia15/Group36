CREATE TABLE Computers (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name VARCHAR NOT NULL,
    type INTEGER NOT NULL,
    yearBuilt INTEGER,
    wasBuilt BOOL
)

CREATE TABLE Scientists (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name VARCHAR NOT NULL,
    sex INTEGER NOT NULL,
    yearBorn INTEGER NOT NULL,
    yearDied INTEGER
)

CREATE TABLE ScientistComputerConnections(
    scientistId integer,
    computerId integer,
    foreign key (scientistId) references Scientists(id),
    foreign key (computerId) references Computers(id),
    primary key(scientistId, computerId)
)