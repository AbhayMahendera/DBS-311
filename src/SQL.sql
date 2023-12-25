
-- Create the Mall table
CREATE TABLE Mall (
    mall_ID INTEGER PRIMARY KEY,
    mallName VARCHAR(50),
    phoneNum INTEGER,
    address VARCHAR(50),
    city VARCHAR(50)
);

-- Create the Maintenance table
CREATE TABLE Maintenance (
    maintenance_ID INTEGER PRIMARY KEY,
    mall_ID INTEGER,
    contractorCompany VARCHAR(50),
    dutyDescription VARCHAR(50),
    scheduledDate DATE,
    FOREIGN KEY (mall_ID) REFERENCES Mall(mall_ID)
);
 -- drop table MALL
 -- drop table MAINTENANCE
 
 
 
 -- Data Insertion for Mall Table
INSERT ALL
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (1, 'City Center Mall', 1234567890, 'Main Street', 'New York')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (2, 'Metro Plaza', 9876543210, 'Broadway Avenue', 'Los Angeles')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (3, 'Central Square', 5551112222, 'Elm Street', 'Chicago')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (4, 'Downtown Mall', 7773331111, 'Oak Avenue', 'Houston')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (5, 'Marketplace Mall', 4445556666, 'Parkway Drive', 'Miami')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (6, 'Pioneer Place', 8887776666, 'Hillside Road', 'San Francisco')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (7, 'Mega Mall', 2223334444, 'Lakeview Boulevard', 'Dallas')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (8, 'Harbor Mall', 1114447777, 'Riverfront Road', 'Seattle')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (9, 'Town Center Mall', 5558889999, 'Sunset Lane', 'Atlanta')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (10, 'Fashion Square', 3332221111, 'Crescent Avenue', 'Phoenix')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (11, 'Lakeside Mall', 9997775555, 'Maple Street', 'Denver')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (12, 'Southgate Mall', 6669993333, 'Lakeshore Drive', 'Detroit')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (13, 'Westfield Mall', 1112223333, 'Greenwood Avenue', 'Boston')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (14, 'Galleria Mall', 5554443333, 'Magnolia Street', 'Philadelphia')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (15, 'Riverside Plaza', 7776665555, 'Waterfront Road', 'San Diego')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (16, 'Valley View Mall', 2221114444, 'Pinecrest Lane', 'Minneapolis')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (17, 'Northgate Shopping Center', 3335558888, 'Rosewood Avenue', 'Tampa')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (18, 'Gateway Mall', 8885552222, 'Cypress Drive', 'Portland')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (19, 'Harmony Mall', 6667778888, 'Willow Road', 'Raleigh')
    INTO Mall (mall_ID, mallName, phoneNum, address, city) VALUES (20, 'Oakwood Center', 1112223333, 'Cedar Street', 'Las Vegas')
SELECT * FROM dual;





-- Data Insertion for Maintenance Table
INSERT ALL
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (101, 1, 'ABC Contractors', 'Electrical Repairs', TO_DATE('2023-10-10', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (102, 2, 'XYZ Services', 'Plumbing Maintenance', TO_DATE('2023-10-15', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (103, 3, 'Maintenance Inc.', 'HVAC System Check', TO_DATE('2023-10-20', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (104, 4, 'Builders R Us', 'Roof Inspection', TO_DATE('2023-10-25', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (105, 5, 'Fix-It All', 'Floor Cleaning', TO_DATE('2023-10-30', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (106, 6, 'RenovatePro', 'Security System Upgrade', TO_DATE('2023-11-05', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (107, 7, 'MegaFix', 'Elevator Maintenance', TO_DATE('2023-11-10', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (108, 8, 'Cooling Experts', 'Air Conditioning Repair', TO_DATE('2023-11-15', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (109, 9, 'PowerTech', 'Generator Inspection', TO_DATE('2023-11-20', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (110, 10, 'Lighting Solutions', 'Lighting Maintenance', TO_DATE('2023-11-25', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (111, 11, 'Plaza Services', 'Facility Cleaning', TO_DATE('2023-11-30', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (112, 12, 'South Maintenance', 'Exterior Repairs', TO_DATE('2023-12-05', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (113, 13, 'Westside Renovations', 'Painting Services', TO_DATE('2023-12-10', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (114, 14, 'Galleria Builders', 'Structural Inspection', TO_DATE('2023-12-15', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (115, 15, 'Riverfront Repairs', 'Plaza Cleaning', TO_DATE('2023-12-20', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (116, 16, 'Valley Maintenance', 'Landscaping', TO_DATE('2023-12-25', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (117, 17, 'Gateway Services', 'Security Checks', TO_DATE('2023-12-30', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (118, 18, 'GreenTech Solutions', 'Environmental Audit', TO_DATE('2024-01-05', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (119, 19, 'Harmony Repairs', 'Facade Restoration', TO_DATE('2024-01-10', 'YYYY-MM-DD'))
    INTO Maintenance (maintenance_ID, mall_ID, contractorCompany, dutyDescription, scheduledDate)
    VALUES (120, 20, 'FixAll Contractors', 'Fire Alarm Testing', TO_DATE('2024-01-15', 'YYYY-MM-DD'))
SELECT * FROM dual;

