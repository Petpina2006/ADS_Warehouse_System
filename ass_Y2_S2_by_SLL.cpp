#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
//                         STRUCT NODE OF STAFF
// -------------------------------------------------------------------------
struct NodeStaff
{
    int id;
    char name[50];
    char gender[10];
    char dob[20];
    char position[50];
    float salary;
    char phone[20];
    NodeStaff *next;
};
//                         STRUCT NODE OF CATEGORY
// -------------------------------------------------------------------------

struct NodeCategory
{
    int id;   
    char name[50];
    char address[50];
    NodeCategory *next;
};
//                         STRUCT NODE OF CATEGORY
// -------------------------------------------------------------------------
struct NodeProduct
{
    int id;
    char name[50];
    int quantity;
    float price;
    int categoryId;
    NodeProduct *next;
};
struct NodeSale
{
    int id;
    char name[50];
    int qty;
    float price;
    float total;
    NodeSale *next;
};
// GlobaL for list
NodeStaff *StaffList = NULL;
NodeCategory *CategoryList = NULL;
NodeProduct *ProductList = NULL;
NodeSale *SaleList = NULL;
// Function prototypes
NodeStaff *getnodeStaff();
NodeCategory *getnodeCategory();
NodeProduct *getnodeProduct();
void initializeStaff();
void initializeCategory();
void initializeProduct();

// upload to file
void writeData()
{
    // -------- Staff --------
    ofstream staffFile("staffs.txt");
    NodeStaff *s = StaffList;
    while (s != NULL)
    {
        staffFile << s->id << "|"
                  << s->name << "|"
                  << s->gender << "|"
                  << s->dob << "|"
                  << s->position << "|"
                  << s->salary << "|"
                  << s->phone << "\n";
        s = s->next;
    }
    staffFile.close();
    // -------- Category --------
    ofstream catFile("categories.txt");
    NodeCategory *c = CategoryList;
    while (c != NULL)
    {
        catFile << c->id << "|"
                << c->name << "|"
                << c->address << "\n";
        c = c->next;
    }
    catFile.close();
    // -------- Product --------
    ofstream prodFile("products.txt");
    NodeProduct *p = ProductList;
    while (p != NULL)
    {
        prodFile << p->id << "|"
                 << p->name << "|"
                 << p->quantity << "|"
                 << p->price << "|"
                 << p->categoryId << "\n";
        p = p->next;
    }
    prodFile.close();
    // -------- Sales --------
    ofstream saleFile("sales.txt");
    NodeSale *sale = SaleList;
    while (sale != NULL)
    {
        saleFile << sale->id << "|"
                 << sale->name << "|"
                 << sale->qty << "|"
                 << sale->price << "|"
                 << sale->total << "\n";

        sale = sale->next;
    }
    saleFile.close();
    // cout << "Data saved successfully!\n";
}
// read data from file
void readData()
{
    string line;

    // -------- Staff --------
    ifstream staffFile("staffs.txt");
    StaffList = NULL;
    NodeStaff *s, *sPtr = NULL;

    while (getline(staffFile, line))
    {
        s = getnodeStaff();

        sscanf(line.c_str(), "%d|%[^|]|%[^|]|%[^|]|%[^|]|%f|%[^|]",
               &s->id,
               s->name,
               s->gender,
               s->dob,
               s->position,
               &s->salary,
               s->phone);

        s->next = NULL;

        if (StaffList == NULL)
            StaffList = s;
        else
            sPtr->next = s;

        sPtr = s;
    }
    staffFile.close();

    // -------- Category --------
    ifstream catFile("categories.txt");
    CategoryList = NULL;
    NodeCategory *c, *cPtr = NULL;

    while (getline(catFile, line))
    {
        c = getnodeCategory();

        sscanf(line.c_str(), "%d|%[^|]|%[^|]",
               &c->id,
               c->name,
               c->address);

        c->next = NULL;

        if (CategoryList == NULL)
            CategoryList = c;
        else
            cPtr->next = c;

        cPtr = c;
    }
    catFile.close();

    // -------- Product --------
    ifstream prodFile("products.txt");
    ProductList = NULL;
    NodeProduct *p, *pPtr = NULL;

    while (getline(prodFile, line))
    {
        p = getnodeProduct();

        sscanf(line.c_str(), "%d|%[^|]|%d|%f|%d",
               &p->id,
               p->name,
               &p->quantity,
               &p->price,
               &p->categoryId);

        p->next = NULL;

        if (ProductList == NULL)
            ProductList = p;
        else
            pPtr->next = p;

        pPtr = p;
    }
    prodFile.close();
    // -------- Sales --------
    ifstream saleFile("sales.txt");
    SaleList = NULL;
    NodeSale *sale, *salePtr = NULL;

    while (getline(saleFile, line))
    {
        sale = (NodeSale *)malloc(sizeof(NodeSale));

        sscanf(line.c_str(), "%d|%[^|]|%d|%f|%f",
               &sale->id,
               sale->name,
               &sale->qty,
               &sale->price,
               &sale->total);

        sale->next = NULL;

        if (SaleList == NULL)
            SaleList = sale;
        else
            salePtr->next = sale;

        salePtr = sale;
    }
    saleFile.close();

    // cout << "Data loaded successfully!\n";
}
/*
    =======================================================
                            Staff
    =======================================================
*/
// INITIALIZE
void initializeStaff()
{
    StaffList = NULL;
}
// GETNODE
struct NodeStaff *getnodeStaff()
{
    struct NodeStaff *p;
    p = (struct NodeStaff *)malloc(sizeof(struct NodeStaff)); // allocate memory

    if (p == NULL)
    {
        cout << "Memory allocation failed\n";
        return NULL;
    }

    p->next = NULL;
    return p;
}
// FREE NODE
void freeNode(NodeStaff *p)
{
    free(p);
}
// ADD STAFF
NodeStaff *CreateStaffList(int n)
{
    NodeStaff *p, *ptr = StaffList;

    for (int i = 1; i <= n; i++)
    {
        p = getnodeStaff();

        cout << "Enter Staff " << i << " ID: ";
        cin >> p->id;
        cin.ignore(); // clear buffer

        cout << "Enter Staff Name: ";
        cin.getline(p->name, 50);

        cout << "Enter Staff Gender: ";
        cin.getline(p->gender, 10);

        cout << "Enter Staff Date of Birth: ";
        cin.getline(p->dob, 20);

        cout << "Enter Staff Position: ";
        cin.getline(p->position, 50);

        cout << "Enter Staff Salary: ";
        cin >> p->salary;
        cin.ignore(); // clear buffer

        cout << "Enter Staff Phone: ";
        cin.getline(p->phone, 20);

        p->next = NULL;

        if (StaffList == NULL)
        {
            StaffList = p;
        }
        else
        {
            ptr->next = p;
        }
        ptr = p;
    }
    return StaffList;
}
// VIEW STAFF
void Traverse(NodeStaff *StaffList)
{
    NodeStaff *p = StaffList;
    cout << "\033[33m Id" << setw(20) << "Name" << setw(25) << "Gender" << setw(25) << "Date of birth" << setw(20) << "Position" << setw(20) << "Salary" << setw(30) << "Phone Number \033[0m" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                        Staff List:\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\033[34m                                                             |             \033[0m\n";
    cout << "\033[34m                                                             V             \033[0m\n";
    while (p != NULL)
    {
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << p->id << setw(20);
        cout << p->name << setw(25);
        cout << p->gender << setw(20);
        cout << p->dob << setw(20);
        cout << p->position << setw(20);
        cout << p->salary << setw(20);
        cout << p->phone << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\033[34m                                                             |             \033[0m\n";
        cout << "\033[34m                                                             V             \033[0m\n";
        p = p->next;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                             NULL\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
// Number of Staff
int CountStaff()
{
    int count = 0;
    NodeStaff *p = StaffList;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
// Linear Search
int LinearSearchStaff(NodeStaff *StaffList, int key)
{
    int pos = 0;

    while (StaffList)
    {
        if (StaffList->id == key)
            return pos;

        StaffList = StaffList->next;
        pos++;
    }

    return -1;
}
// sort
void BubbleSortStaffByID(NodeStaff *StaffList)
{
    if (StaffList == NULL)
        return;

    for (NodeStaff *p = StaffList; p != NULL; p = p->next)
    {
        for (NodeStaff *q = p->next; q != NULL; q = q->next)
        {
            if (p->id > q->id)
            {
                // swap only data fields
                swap(p->id, q->id);
                swap(p->salary, q->salary);

                swap(p->name, q->name);
                swap(p->gender, q->gender);
                swap(p->dob, q->dob);
                swap(p->position, q->position);
                swap(p->phone, q->phone);
            }
        }
    }
}
// delete staff
NodeStaff *DeleteStaff(NodeStaff *StaffList, int id)
{
    NodeStaff *p = StaffList, *prev = NULL;

    // search node
    while (p != NULL && p->id != id)
    {
        prev = p;
        p = p->next;
    }

    // not found
    if (p == NULL)
    {
        cout << "Staff not found!\n";
        return StaffList;
    }

    // delete first node
    if (prev == NULL)
    {
        StaffList = p->next;
    }
    else
    {
        prev->next = p->next;
    }

    freeNode(p);
    cout << "Deleted successfully!\n";

    return StaffList;
}
// update staff
NodeStaff *UpdateStaff(NodeStaff *StaffList, int id)
{
    NodeStaff *p = StaffList;

    // search node
    while (p != NULL && p->id != id)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Staff not found!\n";
        return StaffList;
    }

    // update data
    cout << "Updating Staff ID: " << id << endl;
    cin.ignore();

    cout << "Enter New Name: ";
    cin.getline(p->name, 50);

    cout << "Enter New Gender: ";
    cin.getline(p->gender, 10);

    cout << "Enter New DOB: ";
    cin.getline(p->dob, 20);

    cout << "Enter New Position: ";
    cin.getline(p->position, 50);

    cout << "Enter New Salary: ";
    cin >> p->salary;
    cin.ignore();

    cout << "Enter New Phone: ";
    cin.getline(p->phone, 20);

    cout << "Updated successfully!\n";

    return StaffList;
}
/*
    =======================================================
                            Category
    =======================================================
*/
// INITIALIZE
void initializeCategory()
{
    CategoryList = NULL;
}
// GETNODE
struct NodeCategory *getnodeCategory()
{
    struct NodeCategory *p;
    p = (struct NodeCategory *)malloc(sizeof(struct NodeCategory)); // allocate memory

    if (p == NULL)
    {
        cout << "Memory allocation failed\n";
        return NULL;
    }

    p->next = NULL;
    return p;
}
// FREE NODE
void freeNode(NodeCategory *p)
{
    free(p);
}
// ADD CATEGORY
NodeCategory *CreateCategoryList(int n)
{
    NodeCategory *p, *ptr = CategoryList;
    for (int i = 1; i <= n; i++)
    {
        p = getnodeCategory();

        cout << "Enter Category " << i << " ID: ";
        cin >> p->id;
        cin.ignore(); // clear buffer

        cout << "Enter Category Name: ";
        cin.getline(p->name, 50);

        cout << "Enter Category Address: ";
        cin.getline(p->address, 50);

        p->next = NULL;

        if (CategoryList == NULL)
        {
            CategoryList = p;
        }
        else
        {
            ptr->next = p;
        }
        ptr = p;
    }
    return CategoryList;
}
// VIEW CATEGORY
void Traverse(NodeCategory *CategoryList)
{
    NodeCategory *p = CategoryList;

    cout << "\033[32m Id" << setw(20) << "Name" << setw(25) << "Address\033[0m" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "                Category List:\n";
    cout << "--------------------------------------------------------" << endl;
    cout << "\033[34m                    |             \033[0m\n";
    cout << "\033[34m                    V             \033[0m\n";
    while (p != NULL)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << p->id << setw(20);
        cout << p->name << setw(25);
        cout << p->address << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "\033[34m                    |             \033[0m\n";
        cout << "\033[34m                    V             \033[0m\n";
        p = p->next;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "                  NULL\n";
    cout << "--------------------------------------------------------" << endl;
}
// Number of Category
int CountCategory()
{
    int count = 0;
    NodeCategory *p = CategoryList;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
// Linear Search
int LinearSearchCategory(NodeCategory *CategoryList, int key)
{
    int pos = 0;

    while (CategoryList)
    {
        if (CategoryList->id == key)
            return pos;

        CategoryList = CategoryList->next;
        pos++;
    }

    return -1;
}
// sort
void BubbleSortCategoryByID(NodeCategory *CategoryList)
{
    if (CategoryList == NULL)
        return;

    for (NodeCategory *p = CategoryList; p != NULL; p = p->next)
    {
        for (NodeCategory *q = p->next; q != NULL; q = q->next)
        {
            if (p->id > q->id)
            {
                // swap only data fields
                swap(p->id, q->id);
                swap(p->name, q->name);
                swap(p->address, q->address);
            }
        }
    }
}
// delete category
NodeCategory *DeleteCategory(NodeCategory *CategoryList, int id)
{
    NodeCategory *p = CategoryList, *prev = NULL;

    // search node
    while (p != NULL && p->id != id)
    {
        prev = p;
        p = p->next;
    }

    // not found
    if (p == NULL)
    {
        cout << "Category not found!\n";
        return CategoryList;
    }

    // delete first node
    if (prev == NULL)
    {
        CategoryList = p->next;
    }
    else
    {
        prev->next = p->next;
    }

    freeNode(p);
    cout << "Deleted successfully!\n";

    return CategoryList;
}
// update category
NodeCategory *UpdateCategory(NodeCategory *CategoryList, int id)
{
    NodeCategory *p = CategoryList;

    // search node
    while (p != NULL && p->id != id)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Category not found!\n";
        return CategoryList;
    }

    // update data
    cout << "Updating Category ID: " << id << endl;
    cin.ignore();

    cout << "Enter New Name: ";
    cin.getline(p->name, 50);

    cout << "Enter New Gender: ";
    cin.getline(p->address, 50);

    cout << "Updated successfully!\n";

    return CategoryList;
}
/*
    =======================================================
                            Product
    =======================================================
*/
// INITIALIZE
void initializeProduct()
{
    ProductList = NULL;
}
// GETNODE
struct NodeProduct *getnodeProduct()
{
    struct NodeProduct *p;
    p = (struct NodeProduct *)malloc(sizeof(struct NodeProduct)); // allocate memory

    if (p == NULL)
    {
        cout << "Memory allocation failed\n";
        return NULL;
    }

    p->next = NULL;
    return p;
}

// FREE NODE
void freeNode(NodeProduct *p)
{
    free(p);
}
// ADD PRODUCT
NodeProduct *CreateProductList(int n)
{
    NodeProduct *p, *ptr = ProductList;
    for (int i = 1; i <= n; i++)
    {
        p = getnodeProduct();

        cout << "Enter Product " << i << " ID: ";
        cin >> p->id;
        cin.ignore();

        cout << "Enter Product Name: ";
        cin.getline(p->name, 50);

        cout << "Enter Product Quantity: ";
        cin >> p->quantity;

        cout << "Enter Product Price: ";
        cin >> p->price;

        cout << "Enter Product CategoryID: ";
        cin >> p->categoryId;

        p->next = NULL;

        if (ProductList == NULL)
        {
            ProductList = p;
        }
        else
        {
            ptr->next = p;
        }
        ptr = p;
    }
    return ProductList;
}
// VIEW PRODUCT
void Traverse(NodeProduct *ProductList)
{
    NodeProduct *p = ProductList;

    cout << "\033[35m Id" << setw(20) << "Name" << setw(25) << "Quantity" << setw(20) << "Price" << setw(30) << "CategoryID\033[0m" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "                                       Product List:                                              \n";
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    cout << "\033[34m                                            |             \033[0m\n";
    cout << "\033[34m                                            V             \033[0m\n";
    while (p != NULL)
    {
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << p->id << setw(20);
        cout << p->name << setw(25);
        cout << p->quantity << setw(20);
        cout << p->price << setw(20);
        cout << p->categoryId << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << "\033[34m                                            |             \033[0m\n";
        cout << "\033[34m                                            V             \033[0m\n";

        p = p->next;
    }

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "                                             NULL                                              \n";
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}
// Number of product
int CountProduct()
{
    int count = 0;
    NodeProduct *p = ProductList;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
// Linear Search
int LinearSearchProduct(NodeProduct *ProductList, int key)
{
    int pos = 0;

    while (ProductList)
    {
        if (ProductList->id == key)
            return pos;

        ProductList = ProductList->next;
        pos++;
    }

    return -1;
}
// sort
void BubbleSortProductByID(NodeProduct *ProductList)
{
    if (ProductList == NULL)
        return;

    for (NodeProduct *p = ProductList; p != NULL; p = p->next)
    {
        for (NodeProduct *q = p->next; q != NULL; q = q->next)
        {
            if (p->id > q->id)
            {
                // swap only data fields
                swap(p->id, q->id);
                swap(p->name, q->name);
                swap(p->quantity, q->quantity);
                swap(p->price, q->price);
                swap(p->categoryId, q->categoryId);
            }
        }
    }
}
// delete product
NodeProduct *DeleteProduct(NodeProduct *ProductList, int id)
{
    NodeProduct *p = ProductList, *prev = NULL;

    // search node
    while (p != NULL && p->id != id)
    {
        prev = p;
        p = p->next;
    }

    // not found
    if (p == NULL)
    {
        cout << "Product not found!\n";
        return ProductList;
    }

    // delete first node
    if (prev == NULL)
    {
        ProductList = p->next;
    }
    else
    {
        prev->next = p->next;
    }

    freeNode(p);
    cout << "Deleted successfully!\n";

    return ProductList;
}
// update product
NodeProduct *UpdateProduct(NodeProduct *ProductList, int id)
{
    NodeProduct *p = ProductList;

    // search node
    while (p != NULL && p->id != id)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Product not found!\n";
        return ProductList;
    }

    // update data
    cout << "Updating Product ID: " << id << endl;
    cin.ignore();

    cout << "Enter New Name: ";
    cin.getline(p->name, 50);
    cout << "Enter New Quantity: ";
    cin >> p->quantity;
    cout << "Enter New Price: ";
    cin >> p->price;
    cout << "Enter New CategoryID: ";
    cin >> p->categoryId;

    cout << "Updated successfully!\n";

    return ProductList;
}

/*
    =======================================================
                            Sale
    =======================================================
*/
void ShowProductMenu(NodeProduct *plist)
{
    cout << "\n====== PRODUCT MENU ======\n";
    cout << "ID\tName\t\tPrice\n";
    cout << "-----------------------------------\n";

    while (plist != NULL)
    {
        cout << plist->id << "\t"
             << plist->name << "\t\t"
             << plist->price << "$" << endl;

        plist = plist->next;
    }

    cout << "-----------------------------------\n";
}
void SaleProduct()
{
    readData();

    int id, qty;
    NodeProduct *p = ProductList;

    ShowProductMenu(ProductList);

    cout << "Enter Product ID to sell: ";
    cin >> id;

    // search product
    while (p != NULL && p->id != id)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Product not found!\n";
        return;
    }

    if (p->quantity == 0)
    {
        cout << "This product is OUT OF STOCK!\n";
        return;
    }

    cout << "\nProduct Name: " << p->name << endl;
    cout << "Price: " << p->price << "$" << endl;
    cout << "Available Quantity: " << p->quantity << endl;

    cout << "Enter quantity to sell: ";
    cin >> qty;

    if (qty <= 0)
    {
        cout << "Invalid quantity!\n";
        return;
    }

    if (qty > p->quantity)
    {
        cout << "Not enough stock!\n";
        return;
    }

    // reduce quantity
    p->quantity -= qty;

    float total = qty * p->price;

    // ===== SAVE SALE (ADD HERE) =====
    NodeSale *s = (NodeSale *)malloc(sizeof(NodeSale));

    s->id = p->id;
    strcpy(s->name, p->name);
    s->qty = qty;
    s->price = p->price;
    s->total = total;
    s->next = NULL;

    if (SaleList == NULL)
    {
        SaleList = s;
    }
    else
    {
        NodeSale *temp = SaleList;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = s;
    }

    // ===== RECEIPT =====
    cout << "\033[33m\n======= RECEIPT =======\033[0m\n";
    cout << "\033[33mProduct: " << p->name << "\033[0m" << endl;
    cout << "\033[33mQuantity: " << qty << "\033[0m" << endl;
    cout << "\033[33mPrice: " << p->price << "$" << "\033[0m" << endl;
    cout << "\033[33mTotal: " << total << "$" << "\033[0m" << endl;
    cout << "\033[33m=======================\033[0m\n";

    writeData();
}
/*
    =======================================================
                            In Stock
    =======================================================
*/
void ShowInStock()
{
    readData();

    NodeProduct *p = ProductList;

    cout << "\n\033[32m======= IN STOCK PRODUCTS =======\033[0m\n";
    cout << "ID\tName\tQty\tStatus\n";
    cout << "------------------------------------------\n";

    while (p != NULL)
    {
        cout << p->id << "\t"
             << p->name << "\t"
             << p->quantity << "\t";

        if (p->quantity > 0)
            cout << "\033[32mIn Stock\033[0m";
        else
            cout << "\033[31mOut of Stock\033[0m";

        cout << endl;

        p = p->next;
    }

    cout << "------------------------------------------\n";
}

/*
    =======================================================
                            report
    =======================================================
*/
void reportMenu()
{
    readData();

    cout << "\033[33m\n================= REPORT =================\033[0m\n";

    // ===== Summary =====
    cout << "\033[34mTotal Staff     : " << CountStaff() << "\033[0m" << endl;
    cout << "\033[34mTotal Category  : " << CountCategory() << "\033[0m" << endl;
    cout << "\033[34mTotal Product   : " << CountProduct() << "\033[0m" << endl;

    cout << "\n\033[32m--------- STOCK REPORT ---------\033[0m\n";
    cout << "\033[32m ID\tName\tQty\tPrice\tTotalValue\033[0m\n";
    cout << "\033[32m------------------------------------------\033[0m\n";

    float grandTotal = 0;
    int lowStockCount = 0;

    NodeProduct *p = ProductList;

    while (p != NULL)
    {
        float totalValue = p->quantity * p->price;
        grandTotal += totalValue;

        cout << "\033[32m" << p->id << "\t" << p->name << "\t" << p->quantity << "\t" << p->price << "$\t" << totalValue << "$" << "\033[0m" << endl;

        // Low stock alert
        if (p->quantity <= 5)
        {
            lowStockCount++;
        }

        p = p->next;
    }

    cout << "\033[32m------------------------------------------\033[0m\n";
    cout << "\033[32mTOTAL INVENTORY VALUE: $" << grandTotal << "\033[0m" << endl;

    cout << "\n\033[31m--------- SALES REPORT ---------\033[0m\n";
    cout << "\033[31mID\tName\tQty\tPrice\tTotal\033[0m\n";
    cout << "\033[31m------------------------------------------\033[0m\n";

    NodeSale *s = SaleList;
    float salesGrandTotal = 0;

    while (s != NULL)
    {
        cout << "\033[31m" << s->id << "\t" << s->name << "\t" << s->qty << "\t" << s->price << "\t" << s->total << "\033[0m" << endl;

        salesGrandTotal += s->total;

        s = s->next;
    }

    cout << "\033[31m------------------------------------------\033[0m\n";
    cout << "\033[31mTOTAL SALES: $" << salesGrandTotal << "\033[0m" << endl;
    cout << "\n--------- LOW STOCK ALERT ---------\n";
    if (lowStockCount == 0)
        cout << "No low stock products.\n";
    else
        cout << "Products with quantity <= 5 exist!\n";

    cout << "==========================================\n";
}
/*
    =======================================================
                           Option
    =======================================================
*/

void StaffOption()
{
    initializeStaff();
    int ch, n;
    do
    {
        cout << "\n ----------------------- Staff List -----------------------\n";
        cout << "\033[1;34m 1. Add Staff \033[0m\n";
        cout << "\033[1;32m 2. View Staff \033[0m\n";
        cout << "\033[1;33m 3. Sort Staff \033[0m\n";
        cout << "\033[38;5;208m 4. LinearSearch Staff \033[0m\n";
        cout << "\033[38;2;255;165;0m 5. Update Staff \033[0m\n";
        cout << "\033[1;31m 6. Delete Staff \033[0m\n";
        cout << "\033[1;35m 7. Count Staff \033[0m\n";
        cout << "\033[1;30m 0. Back \033[0m\n";
        cout << "Choose: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter number of staff: ";
            cin >> n;
            StaffList = CreateStaffList(n);
            writeData();
            cout << "Added data successfully for Staff";
        }
        else if (ch == 2)
        {
            readData();
            Traverse(StaffList);
        }
        else if (ch == 3)
        {
            readData();
            BubbleSortStaffByID(StaffList);
            writeData();
        }
        else if (ch == 4)
        {
            readData();
            int id, pos;

            cout << "Enter Staff ID to search: ";
            cin >> id;

            pos = LinearSearchStaff(StaffList, id);

            if (pos == -1)
                cout << "Not found!\n";
            else
                cout << "Found at position: " << pos << endl;
        }
        else if (ch == 5)
        {
            readData();

            int id;
            cout << "Enter Staff ID to update: ";
            cin >> id;

            StaffList = UpdateStaff(StaffList, id);

            writeData();
        }
        else if (ch == 6)
        {
            readData();

            int id;
            cout << "Enter Staff ID to delete: ";
            cin >> id;

            StaffList = DeleteStaff(StaffList, id);

            writeData();
        }
        else if (ch == 7)
        {
            readData();
            cout << "Total Staff = " << CountStaff() << endl;
        }
    } while (ch != 0);
}
void CategoryOption()
{
    initializeCategory();

    int ch, n;
    do
    {
        cout << "\n ----------------------- Category List -----------------------\n";
        cout << "\033[1;34m 1. Add Category \033[0m\n";
        cout << "\033[1;32m 2. View Category \033[0m\n";
        cout << "\033[1;33m 3. Sort Category \033[0m\n";
        cout << "\033[38;5;208m 4. LinearSearch Category \033[0m\n";
        cout << "\033[38;2;255;165;0m 5. Update Category \033[0m\n";
        cout << "\033[1;31m 6. Delete Category \033[0m\n";
        cout << "\033[1;35m 7. Count Category \033[0m\n";
        cout << "\033[1;30m 0. Back \033[0m\n";
        cout << "Choose: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter number of Category: ";
            cin >> n;
            CategoryList = CreateCategoryList(n);
            writeData();
            cout << "\033[31m Added data successfully for Category\033[0m";
        }
        else if (ch == 2)
        {
            readData();
            Traverse(CategoryList);
        }
        else if (ch == 3)
        {
            readData();
            BubbleSortCategoryByID(CategoryList);
            writeData();
        }
        else if (ch == 4)
        {
            readData();
            int id, pos;
            cout << "Enter Category ID to search: ";
            cin >> id;
            pos = LinearSearchCategory(CategoryList, id);
            if (pos == -1)
                cout << "Not found!\n";
            else
                cout << "Found at position: " << pos << endl;
        }
        else if (ch == 5)
        {
            readData();
            int id;
            cout << "Enter Category ID to update: ";
            cin >> id;
            CategoryList = UpdateCategory(CategoryList, id);
            writeData();
        }
        else if (ch == 6)
        {
            readData();
            int id;
            cout << "Enter Category ID to delete: ";
            cin >> id;
            CategoryList = DeleteCategory(CategoryList, id);
            writeData();
        }
        else if (ch == 7)
        {
            readData();
            cout << "Total Category = " << CountCategory() << endl;
        }
    } while (ch != 0);
}
void ProductOption()
{
    initializeProduct();

    int ch, n;
    do
    {
        cout << "\n ----------------------- Product List -----------------------\n";
        cout << "\033[1;34m 1. Add Product \033[0m\n";
        cout << "\033[1;32m 2. View Product \033[0m\n";
        cout << "\033[1;33m 3. Sort Product \033[0m\n";
        cout << "\033[38;5;208m 4. LinearSearch Product \033[0m\n";
        cout << "\033[38;2;255;165;0m 5. Update Product \033[0m\n";
        cout << "\033[1;31m 6. Delete Product \033[0m\n";
        cout << "\033[1;35m 7. Count Product \033[0m\n";
        cout << "\033[1;30m 0. Back \033[0m\n";
        cout << "Choose: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter number of Product: ";
            cin >> n;
            ProductList = CreateProductList(n);
            writeData();
            cout << "Added data successfully for Product";
        }
        else if (ch == 2)
        {
            readData();
            Traverse(ProductList);
        }
        else if (ch == 3)
        {
            readData();
            BubbleSortProductByID(ProductList);
            writeData();
        }
        else if (ch == 4)
        {
            readData();
            int id, pos;

            cout << "Enter Product ID to search: ";
            cin >> id;

            pos = LinearSearchProduct(ProductList, id);

            if (pos == -1)
                cout << "Not found!\n";
            else
                cout << "Found at position: " << pos << endl;
        }
        else if (ch == 5)
        {
            readData();

            int id;
            cout << "Enter Product ID to update: ";
            cin >> id;

            ProductList = UpdateProduct(ProductList, id);

            writeData();
        }
        else if (ch == 6)
        {
            readData();

            int id;
            cout << "Enter Product ID to delete: ";
            cin >> id;

            ProductList = DeleteProduct(ProductList, id);

            writeData();
        }
        else if (ch == 7)
        {
            readData();
            cout << "Total Product = " << CountProduct() << endl;
        }
    } while (ch != 0);
}

void mainMenu()
{
    int ch;
    do
    {
        cout << "\n\033[1;34m===== WAREHOUSE SYSTEM =====\n";
        cout << "1.  Category\n";
        cout << "2.  Staff\n";
        cout << "3.  Product\n";
        cout << "4.  Sale\n";
        cout << "5. Stock In\n";
        cout << "6. Reports\n";
        cout << "0. Exit\n";
        cout << "Choose: \033[0m";
        cin >> ch;

        switch (ch)
        {
        case 1:
            CategoryOption();
            break;
        case 2:
            StaffOption();
            break;
        case 3:
            ProductOption();
            break;
        case 4:
            SaleProduct();
            break;
        case 5:
            readData();
            ShowInStock();
            break;
        case 6:
            reportMenu();
            break;
        }
    } while (ch != 0);
}
// ===== MAIN =====
int main()
{
    cout << "\n=====================Group Member=====================\n";
    cout << "  " << "Name                    Number in list\n";
    cout << "  " << "1. Phal Darith (" << "\033[34mLeader\033[0m" << ")       [ 12 ]\n";
    cout << "  " << "2. Pet Pina                   [ 7 ]\n";
    cout << "  " << "3. Pheaktra Sothanin          [ 24 ]\n";
    cout << "  " << "4. Pheng Sovanreach           [ 20 ]\n";
    cout << "  " << "5. Phern Sopheng              [ 18 ]\n";
    cout << "\n=======================================================\n";
    readData();
    mainMenu();
    return 0;
}