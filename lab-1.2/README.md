
- Student and Instructor use the Serializable interface. JSON parsing uses from_json, which validates the input and decides object validation for the constructors.
- ValidationError occurs/is thrown when there is invalid constructor data, invalid email addresses, missing or invalid JSON fields, invalid roles, and invalid required fields such as office.
- The CSV fields that contain commas, quotes, or newlines are wrapped with quotes. Any quotes inside a field are written twice to signify that. Course lists use semicolons between items for seperation.
