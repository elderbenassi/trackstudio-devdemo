CREATE TABLE Track (
    dbId INTEGER PRIMARY KEY
);

CREATE TABLE Segment (
    dbId INTEGER PRIMARY KEY,
    trackId INTEGER NOT NULL,
    startPointId INTEGER NOT NULL,
    endPointId INTEGER NOT NULL,
    FOREIGN KEY (trackId) REFERENCES Track(dbId),
    FOREIGN KEY (startPointId) REFERENCES Waypoint(dbId),
    FOREIGN KEY (endPointId) REFERENCES Waypoint(dbId)
);

CREATE TABLE Waypoint (
    dbId INTEGER PRIMARY KEY,
    xCoordinate INTEGER NOT NULL,
    yCoordinate INTEGER NOT NULL,
    locationName TEXT
);
